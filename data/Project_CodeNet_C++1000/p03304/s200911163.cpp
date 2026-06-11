#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    int n,m,d;
    cin>>n>>m>>d;
    double ans=(double)(n-d)*(m-1)/n/n;
    if(d!=0)ans*=2;
    cout<<fixed<<setprecision(10)<<ans<<endl;
}