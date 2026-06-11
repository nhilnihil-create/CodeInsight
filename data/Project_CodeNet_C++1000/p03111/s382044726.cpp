#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

void trim(vector<int> a,vector<vector<int>> &g){
    int n=a.size();
    if(n==3){
        g.push_back(a);
        return;
    }
    vector<int> b;
    rep(i,n-1){
        for(int j=i+1;j<n;j++){
            b.push_back(a[i]+a[j]);
            rep(k,n){
                if(k!=i&&k!=j) b.push_back(a[k]);
            }
            trim(b,g);
            b.clear();
        }
    }
}

int main(){
    int n,A,B,C;
    cin>>n>>A>>B>>C;
    vector<int> length(n);
    rep(i,n) cin>>length[i];
    ll mp=INF;   
    for(int bit=0; bit<(1<<n);bit++){
        vector<int> a;
        vector<vector<int>> aa;
        rep(i,n){
            if(bit&(1<<i)) a.push_back(length[i]);
        }
        if(a.size()<=2) continue;
        else{
            trim(a,aa);
            rep(i,aa.size()){
                rep(j,3){
                    rep(k,3){
                        rep(l,3){
                            if((l!=j&& l!=k) && j!=k){
                            ll ans=10*(a.size()-3);
                            ans+=abs(aa[i][j]-A)+abs(aa[i][k]-B)+abs(aa[i][l]-C);
                            mp=min(mp,ans);
                            }
                        }
                    }
                }
            }

        }
    }

    cout<<mp<<endl;
}

