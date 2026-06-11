#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
  int d,g;
  cin >> d >> g;
  vector<int> p(d),c(d);
  for(int i=0;i<d;i++) cin >> p[i] >> c[i];

  int ans = 100000;
  for(int i=1;i<(1<<d);i++){
    ll sum = 0;
    int cnt = 0;
    int m = 0;
    for(int j=d-1;j>=0;j--){
      if((i>>j) & 1 == 1){
        m = j;
      }
    }

    for(int j=d-1;j>=0;j--){
      if((i>>j) & 1 == 1){
        if(j != m){
          sum += (j+1)*100*p[j]+c[j];
          cnt += p[j];
        }else{
          for(int k=0;k<p[j];k++){
            sum += (j+1)*100;
            cnt++;
            if(k == p[j]-1){
              sum += c[j];
            }
            if(sum >= g){
              ans = min(ans,cnt);
              break;
            }
          }
        }
      }
    }

  }

  cout << ans << endl;
}