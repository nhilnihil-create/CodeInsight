#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ll N;
    cin>>N;
    rep(i,3500)for(int j=i;j<3500;j++){
        ll h=i+1,n=j+1;
        ll a=4*h*n-N*h-N*n,b=N*h*n;
        if(a>0&&b%a==0){
            cout<<h<<" "<<n<<" "<<b/a<<"\n";
            return 0;
        }
    }
}