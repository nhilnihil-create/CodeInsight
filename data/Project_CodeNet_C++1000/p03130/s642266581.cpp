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
    vector<vector<int>> path(4);
    rep(i,3){
        int a,b; cin>>a>>b;
        a--; b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    rep(i,4){
        if(path[i].size()>=3){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}
