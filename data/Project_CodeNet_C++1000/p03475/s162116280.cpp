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
    vector<int> c(n-1),s(n-1),f(n-1);
    rep(i,n-1) cin>>c[i]>>s[i]>>f[i];

    rep(i,n-1){
        int ans=s[i]+c[i];
        for(int j=i+1;j<n-1;j++){
            if(ans<=s[j]) ans=s[j]+c[j];
            else{
                if((ans-s[j])%f[j]==0){
                    int x=(ans-s[j])/f[j];
                    ans=s[j]+f[j]*x+c[j];
                }
                else{
                    int x=(ans-s[j]+f[j]-1)/f[j];
                    ans=s[j]+f[j]*x+c[j];
                }
            }
        }

        cout<<ans<<endl;
    }

    cout<<0<<endl;
}
