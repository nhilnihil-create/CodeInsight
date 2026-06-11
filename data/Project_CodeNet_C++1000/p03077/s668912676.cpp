#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
   ll n,a,b,c,d,e;
   cin>>n>>a>>b>>c>>d>>e;
   
   ll damepo=min({a,b,c,d,e});
   cout<<(n+damepo-1)/damepo+4<<endl;   
}