#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
 
int main(){
    ll N;
    string S;
    cin>>N>>S;
    ll ans=0;
    rep(i,0,N){
        map<char,ll> mp1,mp2;
        rep(j,0,i) mp1[S[j]]++;
        rep(j,i,N) mp2[S[j]]++;
        ll cnt=0;
        for(char c='a'; c<='z'; c++){
            if(mp1.count(c)>0 && mp2.count(c)>0)cnt++;
        }
        ans=max(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}