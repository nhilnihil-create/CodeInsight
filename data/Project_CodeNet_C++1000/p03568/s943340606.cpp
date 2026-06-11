#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    //const double PI=3.141592653589793238;


    int N, K, X=0, i=0;
    cin >> N;

    int a[N];

    while(i < N)
    {
        cin >> K;
        if(K%2==0){
            X += 1;
        }
        i++;
    }


    cout << (pow(3, N) - pow(2, X)) << endl;

    return 0;
}