#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int n;
vector<int> prime;
bool is_prime[100000];
vector<int> ans;
int main(){
  cin >> n;
  fill(is_prime, is_prime + 100000, true);
  
  for(int i = 2; i < 100000; i++){
    if(is_prime[i]){
      prime.push_back(i);
      int j = 2;
      while(i * j < 100000){
        is_prime[i*j] = false;
        j++;
      }
    }
  }
  for(int x : prime){
    if(x%5==1 && x <= 55555) ans.push_back(x);
  }
  rep(i, n) printf("%d%c", ans[i], i == n-1 ? '\n': ' ');
}
    
    
  