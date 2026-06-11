#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1001001001;
const ll MOD = 1e9 + 7;
const double PI = 3.14159265358979;


int main(){
  bool prime[100001];
  int like_2017[100001];
  fill(prime, prime + 100001, true);
  prime[0] = false; prime[1] = false;
  for(int i = 2; i < 100001; i++){
    if(prime[i]){
      for(int j = 2; i * j < 100001; j++){
        prime[i * j] = false;
      }
    }
  }
  fill(like_2017, like_2017 + 100001, 0);
  for(int i = 1; i < 100001; i ++){
    if(i % 2 == 0){
      like_2017[i] = like_2017[i-1];
      continue;
    }
    if(prime[i] && prime[(i+1)/2]) like_2017[i] = like_2017[i-1] + 1;
    else like_2017[i] = like_2017[i-1];
  }
  
  int q;
  cin >> q;
  rep(i, q){
    int l, r;
    cin >> l >> r;
    cout << like_2017[r] - like_2017[l-1] <<endl;
  }
}
      
  