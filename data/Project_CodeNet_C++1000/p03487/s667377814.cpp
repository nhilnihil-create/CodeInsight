#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  map<long, long> map;
  for(long i=0; i<N; i++){
    long a;
    cin >> a;
    map[a]++;
  }

  long long ans = 0;
  for(auto pair : map){
    if(pair.first < pair.second){
      ans += pair.second - pair.first;
    }else if(pair.first > pair.second){
      ans += pair.second;
    }
  }

  cout << ans << endl;
}