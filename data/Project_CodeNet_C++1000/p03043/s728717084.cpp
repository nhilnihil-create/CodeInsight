#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  int n,k;
  cin >> n >> k;
  double ans=0;
  for(int i=1; i<(n+1);i++){
    int count=0;
    int tot=i;
    while(tot < k){
      tot*=2;
      count +=1;
    }
    ans += double(1/pow(2,count));
//    cout << pow(2,count) << endl;
  }
  printf("%.20f\n", double(ans/n));
  return 0;
}
