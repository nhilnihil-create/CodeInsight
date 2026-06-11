#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n) ; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main(){
  int n,m,ans;
  cin >> n >> m;
  ans=n%2+m%2;
  if(ans<2) {
    printf("Even");
  }
  else{
    printf("Odd");
  }
  //cout << n <<endl;
    return 0;
}
