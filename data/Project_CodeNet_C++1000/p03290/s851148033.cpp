#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define N 4

int main() {
  int D, G;
  vector<int> p(10);
  vector<int> c(10);
  vector<int> complete_score(10);
  
  int count = 0;
  int score = 0;
  int res = 0;

  cin >> D >> G;
  rep(i,D){
    cin >> p.at(i) >> c.at(i);
    complete_score.at(i) = (i+1)*100*p.at(i)+c.at(i);
    res += p.at(i);
  }

  rep(tmp,1 << D){
    bitset<10> index(tmp);
    bool finished = false;

    score = 0;
    count = 0;
    rep(i,D){
      if(index.test(i) == 1){
        score += complete_score.at(D-i-1);
        count += p.at(D-i-1);
      }
    }
    
    if(G <= score){
      res = min(res, count);
    }
    else{
      rep(i,D){
        if(index.test(i) == 1){
          continue;
        }
        rep(j,p.at(D-i-1)){
          score += 100*(D-i);
          count++;
         
          if(G <= score){
            res = min(res, count);
            finished = true;
            break;
          }
        }
        if(finished){
          break;
        }
      }
    }
  }

  cout << res << endl;
  return 0;
}