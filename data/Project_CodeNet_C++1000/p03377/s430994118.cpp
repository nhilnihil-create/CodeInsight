#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  int a,b,x;cin>>a>>b>>x;
  Ans(a+b>=x&&a<=x);
}
