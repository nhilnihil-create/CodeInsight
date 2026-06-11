#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    int s;
    cin >> s;
    if(s == 25){
        cout << "Christmas" << endl;
    }else if(s == 24){
        cout << "Christmas Eve" << endl;
    }else if(s == 23){
        cout << "Christmas Eve Eve" << endl;
    }else{
        cout << "Christmas Eve Eve Eve" << endl;
    }
}

