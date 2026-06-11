#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int d,g;
  cin >> d >> g;
  vector<int> num(d);
  vector<int> comp(d);
  rep(i,d){
      cin >> num[i] >> comp[i];
  }
  int score,question,ans = INT_MAX ;
  rep(bit,1<<d){
    score = 0;question = 0;
    rep(i,d){
      if(bit&(1<<i)){
        question += num[i];
        score += comp[i]+num[i]*100*(i+1);
      }
    }
    
    
    if(score < g){
      rep(i,d){
        if(!(bit&(1<<(d-i-1)))){
          double haiten = 100*(d-i);
          if(g-score <= haiten*num[d-i-1]){
            question += ceil((g-score) / haiten);
            break;
          }else{
            question += num[d-i-1];
            score += haiten * num[d-i-1];
          }
        }
      }
    }
    ans = min(ans,question);

  }
  cout<< ans << endl;
}

