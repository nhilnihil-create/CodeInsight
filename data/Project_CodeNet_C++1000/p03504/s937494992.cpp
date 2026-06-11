#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int N,C;
    cin>>N>>C;
    vector<vector<bool>> v(30,vector<bool>(100001,false));
    int s,t,c;
    int res=0;
    REP(i,N){
        cin>>s>>t>>c;c--;
        FOR(j,s-1,t)v[c][j]=true;
    }
    REP(i,100001){
        int cnt=0;
        REP(j,30){
            if(v[j][i])cnt++;
        }
        res=max(res,cnt);
    }
    cout<<res<<endl;
    return 0;
}