#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n,m;  cin >> n >> m;
  vector<int>k(m);
  vector<vector<int> >s(n);
  vector<int>p(m);
  for(int i=0;i<m;i++){
    cin >> k.at(i);
    for(int j=0;j<k.at(i);j++){
      int S;
      cin >>  S;
      s.at(S - 1).push_back(i);
    }
  }
  for(int i=0;i<m;i++){
    cin >> p.at(i);
  }

  long long ans = 0;
  for(int bit=0;bit<(1<<n);bit++){
    vector<int>sw(m);
    for(int i=0;i<n;i++){
      if(bit & (1<<i)){
        for(int j : s.at(i))  sw.at(j)++;
      }
    }
    int count = 0;
    for(int i=0;i<m;i++){
      sw.at(i) %= 2;
      if(sw.at(i) == p.at(i)) count++;
    }
    if(count == m)  ans++;
  }
  cout << ans << endl;
}
