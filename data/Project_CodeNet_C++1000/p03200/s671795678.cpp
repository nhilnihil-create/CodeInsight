#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    string s; cin>>s;
    int Bnum=0;
    ll ans=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='B'){
            Bnum++;
        }else if(s[i]=='W'){
            ans += Bnum;
        }
    }
    cout << ans << endl;
}
