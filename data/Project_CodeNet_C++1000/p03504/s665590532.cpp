//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,c; cin>>n>>c;
    vector<vector<int>> data(30,vector<int>(100001,0));
    rep(i,n){
        int s,t,C; cin>>s>>t>>C;
        data[C-1][s-1]++;
        data[C-1][t-1]--;
    } 
    rep(i,30)rep(j,100000){
        if(data[i][j+1]==1){
            data[i][j+1]--;
            data[i][j]++;
        }
    }
    int ans=0;
    rep(i,30) ans+=data[i][0];
    rep(i,100000){
        int cnt=0;
        rep(j,30){
            data[j][i+1]+=data[j][i];
            cnt+=data[j][i+1];
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}