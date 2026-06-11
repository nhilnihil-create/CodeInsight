#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

int main(){
    int n; cin>>n;
    vector<int> p(n);
    int sum=0;
    rep(i,0,n){
        cin>>p[i];
        sum+=p[i];
    }
    sort(all(p));
    reverse(all(p));
    cout<<sum-p[0]/2<<endl;
}