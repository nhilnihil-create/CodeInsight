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
  int x1, y1, x2, y2;
  cin>>x1>>y1>>x2>>y2;
  int vec1 = x2-x1, vec2 = y2-y1;;
  cout<<x2-vec2<<" "<<y2+vec1<<" "<<x1-vec2<<" "<<y1+vec1<<endl;
}
