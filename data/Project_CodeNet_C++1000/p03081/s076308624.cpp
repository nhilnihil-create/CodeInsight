#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int N,Q;
string s;
char t[SIZE],d[SIZE];
int a,b;

int main(){
  cin >> N >> Q;
  cin >> s;
  rep(i,0,Q) cin >> t[i] >> d[i];
  int l = 0,r = N;
  while(r-l>1){
    int m = (l+r)/2;
    int p = m;
    rep(i,0,Q){
      if(t[i] == s[p]){
        if(d[i] == 'L') p--;
        else p++;
      }
      if(p < 0 || p >= N)break;
    }
    if(p >= 0)r = m;
    else l = m;
  }
  a = l;
  l = 0,r = N;
  while(r-l>1){
    int m = (l+r)/2;
    int p = m;
    rep(i,0,Q){
      if(t[i] == s[p]){
        if(d[i] == 'L') p--;
        else p++;
      }
      if(p < 0 || p >= N)break;
    }
    if(p < N)l = m;
    else r = m;
  }
  b = l;
  cout << b-a << endl;
  return 0;
}
