#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll X,Y;
    cin >> X >> Y;

    ll lim = Y/X;
    int num = 0;
    while(lim > 0){
        lim /= 2;
        num++;
    }
    cout << num << endl;
}