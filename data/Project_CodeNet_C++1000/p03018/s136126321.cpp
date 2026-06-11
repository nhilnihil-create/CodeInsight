#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    string s;
    cin>>s;
    vector<char> v;
    rep(i, s.size()){
        if(i==s.size()-1) v.push_back(s[i]);
        else if(s[i]=='B' && s[i+1]=='C'){
            v.push_back('D');
            i++;
        }
        else {
            v.push_back(s[i]);
        }
    }
    vector<ll> ans;
    ll nowd=0;
    bool ok=false;
    reverse(v.begin(), v.end());
    rep(i, v.size()){
        if(ok){
            if(v[i]=='D') nowd++;
            else if(v[i]=='A'){
                ans.push_back(nowd);
            }
            else {
                ok=false;
                nowd=0;
            }
        }
        else{
            if(v[i]=='D') {
                nowd++;
                ok=true;
            }
        }
    }
    ll res=accumulate(ans.begin(), ans.end(), 0LL);
    cout<<res<<endl;
    return 0;
}