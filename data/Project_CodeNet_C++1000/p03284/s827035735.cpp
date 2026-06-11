#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;
const ll MOD = 1000000007;

int main(){
  int n ,k;
  cin >> n >> k;
  if(n%k == 0){
    cout << 0 <<endl;
  }else{
    cout << 1 <<endl;
  }
}