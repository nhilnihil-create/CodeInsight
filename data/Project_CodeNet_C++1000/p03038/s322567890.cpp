#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>

#define MOD 1000000007

// int max: 2 x 10^9, long long max: 9 x 10^18

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  
  vector<long long> a(n), c(m);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  
  vector<int> b(m);
  for(int i=0; i<m; i++){
    cin >> b[i] >> c[i];
  }
  
  map<int, int, greater<int> > histo;
  
  for(int i=0; i<n; i++){
    histo[a[i]]++;
  }
  
  for(int i=0; i<m; i++){
    histo[c[i]] += b[i];
  }
  
  int nokori = n;
  long long result = 0;
  for(const auto& p: histo){
    if(nokori > p.second){
      result += p.first * p.second;
      nokori -= p.second;
    }else{
      result += nokori * p.first;
      break;
    }
  }
  
  cout << result;

  return 0;
}