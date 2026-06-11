#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }

  ll tmp_sum = 0;
  ll cnt = 0;
  int r = 0;
  for(int l = 0; l < n; ++l){
    while(r < n && (tmp_sum + a[r]) == (tmp_sum ^ a[r])){
      tmp_sum += a[r];
      ++r;
    }

    cnt += r - l;

    if(l == r)++r;
    else tmp_sum -= a[l];
  }

  cout << cnt << endl;

  return 0;
}
