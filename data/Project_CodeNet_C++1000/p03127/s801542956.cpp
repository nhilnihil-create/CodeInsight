#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1e9+7
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin >> A[i];
    int ans=A[0];
    for(int i=1;i<n;i++) ans=gcd(ans,A[i]);
    cout << ans << endl;
}