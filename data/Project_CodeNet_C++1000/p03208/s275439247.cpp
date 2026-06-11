#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    sort(h.begin(),h.end());
    int ans=1000000000;
    for(int i=0;i<n-k+1 ;i++){
        ans=min(ans,h[i+k-1]-h[i]);
    }
    cout << ans << endl;
}
