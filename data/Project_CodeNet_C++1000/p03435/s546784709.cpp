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
    vector<vector<int>> c(3,vector<int>(3,0));
    rep(i,3)rep(j,3) cin>>c[i][j];
    if(c[0][2]-c[0][1]==c[1][2]-c[1][1] &&
       c[1][2]-c[1][1]==c[2][2]-c[2][1] &&
       c[0][1]-c[0][0]==c[1][1]-c[1][0] &&
       c[0][1]-c[0][0]==c[2][1]-c[2][0])
       cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
