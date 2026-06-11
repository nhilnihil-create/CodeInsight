#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vec_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define vec_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
#define yn(ans) cout<<(ans?"Yes":"No")<<endl
#define YN(ans) cout<<(ans?"YES":"NO")<<endl
using namespace std;
using ll = long long;
template <typename T>T digitsum(T n);
template <typename T>bool isPrime(T n);
template <typename T>vector<pair<T, T>> prime_factor(T n);
long long int intpow(long long int,long long int);
template <typename T>T intlog(T);
long long int combination(long long int,long long int);
long long int series_sum(long long int);

int main(){
    ll r,g,b,n,ans=0,b2;
    cin>>r>>g>>b>>n;
    for(int i=0;i*r<=n;i++){
        for(int j=0;j*g<=n;j++){
            b2=n-i*r-j*g;
            if(b2<0)break;
            if(b2%b==0){
                //cerr<<i*r<<" "<<j*g<<" "<<b2<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}