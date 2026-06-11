#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const ll INF = 1001001001;
const ll MOD = 1e9 + 7;

//x * y = m (y >= n)となる最大のxが求める答え
int main(){
  int n, m;
  cin >> n >> m;
  if(m == 1){
    cout << 1 << endl;
    return 0;
  }
  vector<int> vec;
  for(int i = 1; i * i < m; i++){
    if(m % i == 0){
      if(m/i>=n) vec.push_back(i);
      if(i >= n) vec.push_back(m/i);
    }
  }
  sort(all(vec)); reverse(all(vec));
  cout << vec[0] <<endl;
}
    