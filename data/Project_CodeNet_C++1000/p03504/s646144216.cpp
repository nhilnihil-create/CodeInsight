#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int n,C;
    cin>>n>>C;
    vector<vector<int>> vec(C+1,vi(100002,0));
    rep(i,n){
        int s,t,c;
        cin>>s>>t>>c;
        vec[c][s-1]+=1;
        vec[c][t]+=-1;
    }
    for (int i=1;i<C+1;i++){
        int now=0;
        for (int j=0;j<100001;j++){
            now+=vec[i][j];
            if (now>0)vec[i][j]=1;
            else vec[i][j]=0;
        }
    }
    int ans=0;
    for (int i=0;i<100001;i++){
        int ans1=0;
        //cout<<i<<endl;
        for (int j=1;j<C+1;j++){
            //cout<<vec[j][i];
            if (vec[j][i])ans1+=1;
        }
        //cout<<endl;
        ans=max(ans,ans1);
    }
    cout<<ans<<endl;
    

    return 0;
}