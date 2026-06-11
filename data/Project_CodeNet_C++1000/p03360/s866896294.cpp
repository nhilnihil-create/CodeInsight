#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  vector<ll> A(3);
  for(int i=0;i<3;++i) cin>>A[i];
  sort(A.begin(), A.end());
  int K;
  cin>>K;
  for(int i=0;i<K;++i) {
    A[2] *= 2;
  }
  cout<<A[0]+A[1]+A[2]<<endl;
}

