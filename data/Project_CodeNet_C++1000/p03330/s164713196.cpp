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

const double pi=3.141592653589793;

int main() {
    ll n,c;
    cin>>n>>c;
    ll d[c+1][c+1];
    rep(i,c){
        rep(j,c){
            cin>>d[i+1][j+1];
        }
    }
    vll c1(c+1,0);//(i+j)%3=1の色の数
    vll c2(c+1,0);
    vll c3(c+1,0);
    for (int i=1;i<n+1;i++){
        for (int j=1;j<n+1;j++){
            ll col;
            cin>>col;
            if ((i+j)%3==1){
                c1[col]+=1;
            }
            else if ((i+j)%3==2){
                c2[col]+=1;
            }
            else{
                c3[col]+=1;
            }
        }
    }
    ll ans=10000000000000000;
    for (int i=1;i<c+1;i++){
        for (int j=1;j<c+1;j++){
            if (i==j){
                continue;
            }
            for (int k=1;k<c+1;k++){
                if (i==k || j==k){
                    continue;
                }
                ll ans1=0;
                for (int l=1;l<c+1;l++){
                    ans1+=c1[l]*d[l][i]+d[l][j]*c2[l]+d[l][k]*c3[l];        
                }
                ans=min(ans,ans1);
                
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
