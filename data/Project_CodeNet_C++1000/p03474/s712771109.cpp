#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 100000

int main(){
    int a, b; cin >> a >> b;
    int n = a + b + 1;
    string s;
    cin >> s;
    bool exist = true;
    rep(i, n){
        if(i != a){
            if(s[i] == '-'){
                exist = false;
                break;
            }
        }else{
            if(s[i] != '-'){
                exist = false;
                break;
            }
        }
    }
    if(exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}