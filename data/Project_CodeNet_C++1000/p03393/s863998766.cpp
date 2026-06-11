#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;cin>>s;
    string ans;
    if(s=="zyxwvutsrqponmlkjihgfedcba")ans="-1";
    else if(s.size()==26){
        int idx = 24;
        char m = 'z';
        for(; idx>=0; idx--){
            if(s[idx]<s[idx+1])break;
        }
        for(int i = 25; i >idx; i--){
            if(s[i]>s[idx])m=min(m,s[i]);
        }
        ans = s.substr(0,idx)+m;


    }
    else{
        vector<bool> c(26,false);
        for(int i=0; i<s.size(); i++){
            c[s[i]-'a']=true;
        }
        int idx = 0;
        for(; idx<26; idx++){
            if(c[idx]==false)break;
        }
        ans = s + char('a'+idx);
    }
    cout<<ans<<endl;

    return 0;
}