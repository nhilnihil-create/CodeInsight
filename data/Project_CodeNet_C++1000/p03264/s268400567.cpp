#include <iostream>

using namespace std;

int main()
{
    int a;
    int sum = 0;
    cin >> a;
    for (int i = 1 ; i <= a ; i++){
        for (int j = 1 ; j <= i ; j++){
            if (i % 2 == 1){
                if (j % 2 == 0){
                    sum++;
                }
            }else if (j % 2 == 1){
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}
