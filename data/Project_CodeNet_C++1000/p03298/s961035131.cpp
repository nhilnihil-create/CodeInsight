#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    int n;
    ll ans=0;
    string s;
    cin>>n>>s;
    map<string,ll> A[19],B[19];
    rep(i,2){
        rep(bit,1<<n){
            string t;
            int a=0;
            if(!i) rep(j,n) if(bit&(1<<j)) t+=s[j];
            rep(j,n) if(!(bit&(1<<n-j-1))) t+=s[n-j-1+n*i],a++;
            if(i) rep(j,n) if(bit&(1<<j)) t+=s[j+n];
            if(!i) A[a][t]++;
            else B[a][t]++;
        }
    }
    rep(i,n+1)for(auto itr=A[i].begin();itr!=A[i].end();itr++){
        ans+=itr->second*B[n-i][itr->first];
    }
    cout<<ans<<"\n";
}