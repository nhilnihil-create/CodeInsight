#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
#include<math.h>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
#define LINF (long long)4e18

using ll = long long;


int main(){
  int N; cin >> N;
  vector<int> a(N);
  int sum = 0;
  rep(i,N){
     cin >> a[i];
     sum += a[i];
  }
  double ave = (double)sum / N;
  vector<pair<double,int>> P(N);
  rep(i,N){
     P[i].first = fabs(ave - (double)a[i]);
     P[i].second = i;
  }
  sort(P.begin(),P.end());

  cout << P[0].second << endl;

  

}

