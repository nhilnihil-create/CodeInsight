#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

int N;
int f[111][10];
ll p[111][11];

int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>N;
  for(int i=0;i<N;i++) for(int j=0;j<10;j++) cin>>f[i][j];
  for(int i=0;i<N;i++) for(int j=0;j<=10;j++) cin>>p[i][j];

  ll res=-1e9;
  for(int m=1;m<(1<<10);m++) {
    ll tmp=0;
    for(int i=0;i<N;i++){
      int c=0;
      for(int j=0;j<10;j++) if((m&(1<<j)) && f[i][j]) c++;
      tmp += p[i][c];
    }
    res=max(res,tmp);
  }
  cout<<res<<endl;

  return 0;
}
