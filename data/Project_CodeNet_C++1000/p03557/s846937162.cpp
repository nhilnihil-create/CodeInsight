#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;
typedef pair<int,int> P;

#define inf 1e18
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())


priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

void solve(){
    llint n;
    cin >> n;
    vector<llint>a(n),b(n),c(n);
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    for(int i=0;i<n;i++)cin >> c[i];
    sort(a);
    sort(b);
    sort(c);
    llint ans=0;
    for(auto bb:b){
        auto m1=lower_bound(a.begin(),a.end(),bb);
        auto m2=upper_bound(c.begin(),c.end(),bb);
        ans+=distance(a.begin(),m1)*distance(m2,c.end());
    }
    cout << ans << endl;


}

int main(){
    solve();
    return 0;
}



