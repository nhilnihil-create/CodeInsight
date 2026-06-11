#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n) ; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main(){
  int n,m;
  cin >> n >> m;
  if(n%500 > m) {
    printf("No");
  }
  else{
    printf("Yes");
  }
    return 0;
}
