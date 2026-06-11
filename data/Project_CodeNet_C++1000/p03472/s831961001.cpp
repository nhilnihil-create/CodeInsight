#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const ll INF = 1001001001;
const ll MOD = 1e9 + 7;

int main(){
  int n, h;
  cin >> n >> h;
  priority_queue<P> pq;
  rep(i, n){
    int a, b;
    cin >> a >> b;
    P p(a, 0), q(b, 1);
    pq.push(p);pq.push(q);
  }
  int ans = 0;
  while(h > 0){
    P tmp = pq.top();
    h -= tmp.first;
    if(tmp.second) pq.pop();
    ans++;
    
  }
  cout << ans <<endl;
}
  
    