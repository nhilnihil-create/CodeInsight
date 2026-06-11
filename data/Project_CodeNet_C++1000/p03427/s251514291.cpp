#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;


int main(){
    string s;
    cin >> s;
    int n = s.size();
    int c;
    bool flag = true;
    rep(i, n){
        if(i == 0){
            c = s[i] - '0';
        }else{
            if(s[i] != '9'){
                flag = false;
            }
        }
    }
    
    ll ans = 0;
    if(flag){
        ans += c + 9*(n-1); 
    }else{
        ans += (c-1) + 9*(n-1);
    }
    cout << ans << endl;
    return 0;
}