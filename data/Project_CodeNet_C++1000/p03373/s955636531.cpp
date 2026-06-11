#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int a,b,c,x,y;
  cin >>a>>b>>c>>x>>y;
  int ans = pow(10,9);
  for(int i=0;i<=max(x,y)*2;i += 2){
    int tmp_a = max(0,x-i/2);
    int tmp_b = max(0,y-i/2);
    ans = min(ans,tmp_a*a+tmp_b*b+i*c);
  }
  cout << ans << endl;
}