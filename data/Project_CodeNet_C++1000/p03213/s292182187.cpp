#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int N;

int main(){
  cin >> N;

  vector<int> primes;
  vector<int> table(101, 1);
  table[0] = 0;
  table[1] = 0;

  for(int i = 2; i < 101; i++){
    if(table[i] == 0) continue;

    int j = 2*i;
    while(j < 101){
      table[j] = 0;
      j += i;
    }
  }

  for(int i = 0; i < 101; i++){
    if(table[i] == 1) primes.push_back(i);
  }

  map<int, int> cnt;

  for(auto it = primes.begin(); it != primes.end(); it++){
    for(int i = 1; i <= N; i++){
      int val = i;

      while(val % (*it) == 0){
	val /= (*it);
	cnt[(*it)]++;
      }
    }
  }

  int count3 = 0;
  int count5 = 0;
  int count15 = 0;
  int count25 = 0;
  int count75 = 0;

  for(auto it = cnt.begin(); it != cnt.end(); it++){
    if(it->second >= 2) count3++;
    if(it->second >= 4) count5++;
    if(it->second >= 14) count15++;
    if(it->second >= 24) count25++;
    if(it->second >= 74) count75++;
  }

  int ans = 0;

  ans += count75;
  ans += count25 * (count3 - 1);
  ans += count15 * (count5 - 1);
  ans += count5 * (count5 - 1) / 2 * (count3 - 2);

  cout << ans << "\n";
  
  return 0;
}
