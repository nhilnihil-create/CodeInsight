#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
  vector<int> t,v;
  double now_t = 0;
  double now_v = 0;
  double len = 0;
  int n;
  t.push_back(0);
  v.push_back(0);
  cin >> n;
  for(int i = 0; i < n ; i++){
    int a;
    cin >> a;
    t.push_back(a + t[i]);
  }
  for(int i = 0; i < n ; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }
  v.push_back(0);

  int count = 0;
  for(double i = 0; i <= t[n]; i += 0.5){
    double mini = 100;
    if(i >= t[count]) count++;
    for(int j = 0; j <= n; j++){
      if(mini > (i - t[j] + v[j]) && i - t[j] >= 0){
        mini = i - t[j] + v[j];
      }
      if(mini > (t[j] - i + v[j+1]) && t[j] - i >= 0){
        mini = t[j] - i + v[j+1];
      }
    }
    if(mini > v[count]){
      mini = v[count];
    }
    len += 0.25*(now_v + mini);
    now_v = mini;
  }
  printf("%.5lf\n", len);
}
