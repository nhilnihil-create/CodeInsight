#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> vec;
  int current;
  int cnt = 0;
  string str;
  cin >> str;
  if(str[0] == '0') vec.push_back(0);
  rep(i, n){
    int num = str[i]-'0';
    if(i == 0){
      current = num;
      cnt++;
    }else{
      if(num == current) cnt++;
      else{
        current = num;
        vec.push_back(cnt);
        cnt = 1;
      }
      if(i == n-1) vec.push_back(cnt);
    }
  }
  if(str[n-1] == '0') vec.push_back(0);
  if(vec.size() <= k*2+1) cout << n << endl;
  else{
    int sum = 0;
    int biggest = 0;
    rep(i, k*2+1) sum += vec[i];
    rep(i, (vec.size()-(k*2+1))/2+1){
      biggest = max(biggest, sum);
      sum -= vec[i*2];
      sum -= vec[i*2+1];
      if(i != (vec.size()-(k*2+1))/2){
 		sum += vec[i*2+k*2+1];
      	sum += vec[i*2+k*2+2];
      }
    }
    cout << biggest << endl;
  }
  return 0;
}