#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr int Nalp= 26;
  string S;
  cin >> S;

  vector<int> data;
  bitset<Nalp> appear;
  for(auto c:S){
    int ord= c- 'a';
    data.emplace_back(ord);
    appear.set(ord);
  }

  if(data.size() < Nalp){
    int ord_tail= 0;
    while(appear.test(ord_tail)){
      ord_tail++;
    }
    char tail= 'a'+ ord_tail;

    string ans= S+ tail;

    cout << ans << endl;
  }
  else{
    if(next_permutation(data.begin(), data.end())){
      string ans;
      for(int i=0; i<Nalp; i++){
        int ord= data.at(i);
        ans+= 'a'+ ord;
        if(ans.at(i) != S.at(i)){ break; }
      }

      cout << ans << endl;
    }
    else{
      cout << -1 << endl;
    }
  }
}