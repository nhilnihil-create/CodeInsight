#include <bits/stdc++.h>
using namespace std;

int main() {
  int num;
  int mon;
  long long tmp;
  map<long long, long long> m;
  cin >> num;
  
  vector<long long> vec(num);
  for(int i = 0; i < num; i++) cin >> vec.at(i);
  
  cin >> mon;
  
  for(int i = 0; i < mon; i++){
    cin >> tmp;
    m[tmp] += 1;
  }
  
  for(int i =0; i < num; i++){
    auto itr = m.find(vec.at(i));
    if(itr != m.end()){
      m[vec.at(i)] -= 1;
    }
  }
  
  long long Min = -1;
  for(auto itr : m){
    Min = max(Min, itr.second);
  }
  
  if(Min <= 0) cout << "YES";
  else cout << "NO";
}
