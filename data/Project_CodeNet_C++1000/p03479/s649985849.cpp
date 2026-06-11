#include<iostream>
using namespace std;

int main(){
    long long X, Y;
    cin >> X >> Y;

    int res = 0;
    do{
        res++;
        X *= 2;
    }while(X <= Y);

    cout << res << endl;
}
