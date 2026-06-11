#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(){
    llint n;
    vector<llint>a(5);
    cin >> n;
    llint mn=inf;
    for(int i=0;i<5;i++){
        cin >> a[i];
        mn=min(a[i],mn);
    }
    llint ans=0;
    if(n%mn==0){
        ans+=5+n/mn;
    }
    else ans+=6+n/mn;

    cout << ans-1 << endl;


}

int main(){
  solve();
  return 0;
}
