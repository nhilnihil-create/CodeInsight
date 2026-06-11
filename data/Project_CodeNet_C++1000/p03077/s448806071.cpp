#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())

priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(){
    llint n;
    vector<llint>a(5,0);
    cin >> n;
    for(int i=0;i<5;i++)cin >> a[i];
    llint t=a[0];
    for(int i=1;i<5;i++)t=min(a[i],t);
    llint ans=(n+t)/t;
    if(n%t==0)ans=n/t;
    cout << ans+4 << endl;
}

int main(){
  solve();
  return 0;
}
