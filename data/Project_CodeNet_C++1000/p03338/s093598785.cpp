#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int n;cin>>n;string s;cin>>s;
    int ans=0;
    rep1(i,n-1){
        map<char,bool>mp;
        string head=s.substr(0,i);
        string tail=s.substr(i,n-i);
        int cnt = 0;
        rep(j,head.size()){mp[head[j]]=true;}
        rep(j,tail.size()){if(mp[tail[j]]){cnt++;mp[tail[j]]=false;}}
        ans = max(ans,cnt);
    }
    co(ans);

}