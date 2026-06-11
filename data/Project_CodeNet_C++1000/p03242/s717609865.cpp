#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    string n;
    cin >> n;
    rep(i, 3){
        if(n[i] == '1'){
            cout << 9;
        }else if(n[i] == '9'){
            cout << 1;
        }else{
            cout << n[i];
        }
    }
    cout << endl;
}