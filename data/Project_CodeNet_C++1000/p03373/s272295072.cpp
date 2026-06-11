#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int ans=INF;
  for(int c=0;c<=max(X,Y);c++){
   ans=min(C*2*c+max(0,X-c)*A+max(0,Y-c)*B,ans);
  }
  cout<<ans<<endl;
    return 0;
}