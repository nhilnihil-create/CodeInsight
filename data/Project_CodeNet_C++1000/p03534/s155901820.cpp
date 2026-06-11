#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    string s; cin>>s;
    int cnt[3]={};
    for(char c:s){
        cnt[c-'a']++;
    }
    int mi=INF;
    for(int i=0;i<3;i++) mi=min(mi,cnt[i]);
    bool flg=1;
    for(int i=0;i<3;i++){
        cnt[i]-=mi;
        if(cnt[i]>1) flg=0;
    }
    cout<<(flg?"YES":"NO")<<endl;
    return 0;
}
