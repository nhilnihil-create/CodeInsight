#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める

int main(){

  int n;
  cin >> n;

  vector<int> t;
  vector<int> x;
  vector<int> y;

  bool flag = true;

  t.push_back(0);
  x.push_back(0);
  y.push_back(0);

  REP(i,n){
    int t1,x1,y1;
    cin >> t1 >> x1 >> y1;
    t.push_back(t1);
    x.push_back(x1);
    y.push_back(y1);
  }

  int t_t,t_x,t_y;

  REP(i,n){
    // if(t[i] >= x[i]+y[i]){
      // if(i==0){
      //   if((x[i]+y[i])%2 == t[i]%2){
      //     if(i<n-1){
      //       t_t = t[i+1]-t[i];
      //       t_x = abs(x[i+1]-x[i]);
      //       t_y = abs(y[i+1]-y[i]);
      //     }
      //     continue;
      //   } else {
      //     flag = false;
      //     break;
      //   }
      // } else {
    t_t = t[i+1]-t[i];
    t_x = abs(x[i+1]-x[i]);
    t_y = abs(y[i+1]-y[i]);
    if(t_t >= t_x+t_y){
      if((t_x+t_y)%2 == t_t%2){
        // if(i<n-1){
          //   t_t = t[i+1]-t[i];
          //   t_x = abs(x[i+1]-x[i]);
          //   t_y = abs(y[i+1]-y[i]);
          // }
        continue;
      } else {
        flag = false;
        break;
      }
      // }
    } else {
      flag = false;
      break;
    }
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
