#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;

    vector<pair<int,int>> ans;
    if(n%2==1){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i+j==n) continue;
                ans.push_back({i,j});
            }
        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i+j==n+1) continue;
                ans.push_back({i,j});
            }
        }
    }

    cout<<ans.size()<<endl;
    rep(i,ans.size()){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}