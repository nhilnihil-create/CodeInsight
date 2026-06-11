#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, G;
  cin >> D >> G;
  vector<int> p(D);
  vector<int> c(D);
  for (int i = 0; i < D; i++) cin >> p.at(i) >> c.at(i);
  
  int ans = 1000000;
  for (int tmp = 0; tmp < (1 << D); tmp++){
    bitset<10> bits(tmp);
    int score = 0;
    int count = 0;
    for (int i = 0; i < D; i++){
      if (bits.test(i)) {
        score += (100 * (i + 1) * p.at(i) + c.at(i));
        count += p.at(i);
      }
    }
    int max_not_choiced = 0;
    for (int i = D - 1; i >= 0; i--){
      if (!bits.test(i)){
        max_not_choiced = i;
        break;
      }
    }
    
    if (score >= G){
      ans = min(ans, count);
    }
    else if (G - score < 100 * (max_not_choiced + 1) * p.at(max_not_choiced)){
      int z = 0;
      if ((G - score) % (100 * (max_not_choiced + 1)) != 0) z = 1;
      ans = min(ans, count + (G - score) / (100 * (max_not_choiced + 1)) + z);
    }
    //cout << "bits " << bits << endl;
    //cout << "ans " << ans << endl;
  }
  cout << ans << endl;
}
