#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    long long num;
    long long product;
    int p_count;

    cin >> num >> product;

    if(num == 1){
        cout << product << endl;
        return 0;
    }

    long long common_divisor = 1;

    for(long long p = 2; p <= pow(product, (double)1 / num) + 0.9; p++){
        p_count = 0;
        while(product % p == 0){
            product /= p;
            p_count = p_count + 1;
            if(p_count >= num){
                common_divisor *= p;
                p_count = 0;
            }
        }

    }

    cout << common_divisor << endl;

    return 0;
}
