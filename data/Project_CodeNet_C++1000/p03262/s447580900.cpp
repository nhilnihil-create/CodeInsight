//c++ テンプレ
#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;
llint X;

llint gcd(llint x,llint y){
    if(x<y)gcd(y,x);
    llint r;
    while((r=x%y)){
        x=y;
        y=r;
    }
    return y;
}

void solve(){
    cin >> n >> X;
    vector<llint>x(n);
    for(int i=0;i<n;i++)cin >> x[i];
    llint g=abs(X-x[0]);
    for(int i=1;i<n;i++){
        g=gcd(g,abs(X-x[i]));
    }
    cout << g << endl;
}  

int main(){
  solve();
  return 0;
}
