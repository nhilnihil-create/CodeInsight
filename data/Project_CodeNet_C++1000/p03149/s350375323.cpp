
#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    bool ok[4]={0};
    rep(i,4){
        int x;
        cin>>x;
        if(x==1) ok[0]=1;
        if(x==9) ok[1]=1;
        if(x==7) ok[2]=1;
        if(x==4) ok[3]=1;
    }
    bool ans =1;
    rep(i,4){
        if(ok[i]==0) ans = 0;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}