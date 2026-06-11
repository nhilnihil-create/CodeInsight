#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<string> RedCards(N);
  for(int i=0;i<N;i++) cin >> RedCards.at(i);
  
  int M;
  cin >> M;
  vector<string> BlueCards(M);
  for(int i=0;i<M;i++) cin >> BlueCards.at(i);
  
  string s;
  int ans,temp;
  ans=0;
  for(int i=0;i<N;i++){
    temp=0;
    s=RedCards.at(i);
    
    for(int j=0;j<N;j++){
      if(RedCards.at(j)==s) temp++;
    }
    
    for(int j=0;j<M;j++){
      if(BlueCards.at(j)==s) temp--;
    }
    ans=max(ans,temp);
  }
  cout << ans << endl;
}