#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main() {
  long long n, h;
  cin >> n >> h;
  vector<pair<long long, long long>> vec;
  for(long long i=0; i<n; i++){
    long long a, b;
    cin >> a >> b;
    vec.push_back(make_pair(b, a));
  }
  long long biggest = 0;
  for(long long i=0; i<n; i++){
    if(biggest < vec[i].second) biggest = vec[i].second;
  }
  long long count = 0;
  sort(all(vec), std::greater<>());
  for(long long i=0; i<n; i++){
    if(biggest < vec[i].first){
      h -= vec[i].first;
      count++;
      if(h <= 0){
        cout << count << endl;
        return 0;
      }
    }
  }
  if(h % biggest == 0) cout << count + h/biggest << endl;
  else cout << count + h/biggest + 1 << endl;
  return 0;
}
    
    
    
    
    
