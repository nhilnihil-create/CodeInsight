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
    int n; cin>>n;
    string ans="Yes";
    vector<vector<int>> d(n+1,vector<int>(3,0));
    rep(i,n)rep(j,3){
        cin>>d[i+1][j];
    }
    rep(i,n){
        int d1=d[i+1][0]-d[i][0];
        int d2=abs(d[i+1][1]-d[i][1])+abs(d[i+1][2]-d[i][2]);
        if(d1<d2 || (d2-d1)%2)
        ans="No";
    }
    cout<<ans<<endl;
}