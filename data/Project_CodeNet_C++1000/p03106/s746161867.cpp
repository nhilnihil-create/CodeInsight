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

int main(){
  int a, b, k;
  cin >> a >> b >> k;
  vector<int> cd;
  for(int i = 1; i <= 100; i++){
    if(a%i == 0 && b % i == 0) cd.push_back(i);
  }
  reverse(all(cd));
  cout << cd[k-1] <<endl;
}