#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, g;
  cin >> d >> g;

  vector<int> p(d);
  vector<int> c(d);

  for(int i = 0; i < d; i++){
    cin >> p[i] >> c[i];
  }

  int ans = 100000;
  for(int bit = 0; bit < (1 << d); bit++){
    int k = 0;
    int point = 0;
    vector<bool> used(d);

    for(int i = 0; i < d; i++){
      if(bit & (1 << i)){
        k += p[i];
        point += 100*(i+1)*p[i];
        point += c[i];
        used[i] = true;
      }
    }

    if(point < g){
      int i = d-1;
      while(point < g){
        if(used[i] == false){
          for(int j = 0; j < p[i]-1; j++){
            if(point >= g) break;

            point += 100*(i+1);
            k++;
          }
        }

        i--;
        if(i < 0){
          break;
        }
      }
    }

    if(point >= g){
      ans = min(ans, k);
    }
  }

  cout << ans << endl;
  return 0;
}