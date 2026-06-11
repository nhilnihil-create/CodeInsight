#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n,k;    cin>>n>>k;
    vector<ll>x(n);
    rep(i, n)   cin>>x[i];
    ll ans = 1e12;
    rep(i, n-k+1){
        ans = min(ans, abs(x[i]) + abs(x[i+k-1]-x[i]));
        ans = min(ans, abs(x[i+k-1]) + abs(x[i+k-1]-x[i]));
    }
    cout<<ans<<endl;
}
