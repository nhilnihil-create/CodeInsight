#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<ll, ll> P;

int main(){
    int a,b;
    cin >> a >> b;
    string s;
    cin >> s;
    bool ok = true;
    rep(i,a){
        if(s[i]=='-'){
            cout << "No" << endl;
            return 0;
        }
    }

    if(s[a]!='-'){
        cout << "No" << endl;
        return 0;
    }

    rep(i,b){
        if(s[i+a+1]=='-'){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}