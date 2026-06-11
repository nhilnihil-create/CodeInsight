#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, N, M, max=0;
  cin >> N;
  map <string,int> card;
  string s;

  vector<string> blue(N);

  rep(i,N) {
    cin >> blue[i];
    card[blue[i]] +=1;
  }
  cin >> M;
  rep(i,M) {
    cin >> s;
    card[s]-=1;
  }
  rep(i,N){
    if(card[blue[i]]>max) max=card[blue[i]];
  }
  
  cout << max;
}