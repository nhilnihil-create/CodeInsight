#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>v;
    rep(i,1,sqrt(m)+1){
        if(m%i==0){
            v.push_back(i);
            v.push_back(m/i);
        }
    }
    int ans=0;
    rep(i,0,v.size()){
        if((m/v.at(i))<n)continue;
        ans=max(ans,v.at(i));
    }
    cout<<ans<<endl;
return 0;
}