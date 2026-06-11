#include <bits/stdc++.h>
using namespace std;
#define rep0(i, a) for(int i=0;i < (a); i++)
#define rep(i, a, b) for(int i=(a);i < (b); i++)


int main(){
  int i,j,k, D, G;
  cin >> D >> G;
  pair<int, int> tmp;
  vector<pair<int, int>> P;
  rep0(i, D){
    cin >> tmp.first >> tmp.second;
    P.push_back(tmp);
  }
  int total, num, min_num;
  min_num = 1 << 30;
  rep0(i, (1<<D)){
    total = 0;num = 0;
    bitset<10> bit(i);
    rep0(k, D){
      if(bit.test(k)){
        total += P[k].second + (100 * (k+1) * P[k].first);
        num += P[k].first;
      }
    }
    //cout << bit << " " << total << ", " << num << endl;
    if(total >= G){
      if(min_num > num){min_num = num;continue;}
    }
    if(total < G){
      for(k=D-1; k>=0; k--){
        if(!bit.test(k)){

          if (P[k].first > (G-total)/(100*(k+1))){
            
            if ((G-total)%(100*(k+1)) == 0){
              num += (G-total)/(100*(k+1));
            }
            else{
              num += (G-total)/(100*(k+1)) + 1;
            }
            if (min_num > num){
              min_num = num;
            }
          break;
            
          }
        }
      }
    }
  }

  cout << min_num << endl;
}