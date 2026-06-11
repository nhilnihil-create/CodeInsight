#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    int tmp;
    int fx = 0;
    cin >> N;
    tmp = N;

    int amari = 0;
    while( tmp > 0){
        amari = tmp % 10;
        fx = fx + amari;
        tmp = tmp / 10;
    }

    if(N % fx == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}