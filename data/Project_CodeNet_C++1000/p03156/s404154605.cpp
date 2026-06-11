#define _GLIBCXX_DEBUG
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
    int n,a,b; cin>>n>>a>>b;
    vector<int> ans(3,0);
    rep(i,n){
        int p; cin>>p;
        if(p<=a) ans[0]++;
        else if(p>=b+1) ans[2]++;
        else ans[1]++; 
    }
    cout<<min(ans[0],min(ans[1],ans[2]))<<endl;
}
