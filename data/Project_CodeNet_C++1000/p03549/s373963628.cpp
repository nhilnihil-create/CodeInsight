#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n,m;
    cin>>n>>m;
    int ans=(1900*m+100*(n-m))*pow(2,m);
    cout<<ans<<endl;
}