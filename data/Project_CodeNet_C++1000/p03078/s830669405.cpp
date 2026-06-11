#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end(), greater<ll>())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

bool added[1005][1005][1005];

struct element{
  ll abc;
  int ei;
  int ej;
  int ek;
};

struct Compareabc {
    bool operator()(element const& p1, element const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.abc < p2.abc;
    }
};

int main(){
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x);
  vector<ll> b(y);
  vector<ll> c(z);
  rep(i, x){
    cin >> a[i];
  }
  rep(i, y){
    cin >> b[i];
  }
  rep(i, z){
    cin >> c[i];
  }
  ssort(a);ssort(b);ssort(c);
  priority_queue<element, vector<element>, Compareabc> PQ;
  element e0={a[0]+b[0]+c[0], 0, 0, 0};
  PQ.push(e0);
  rep(qi, k){
    element p=PQ.top(); PQ.pop();
    cout << p.abc << endl;
    if(p.ei+1<x && !added[p.ei+1][p.ej][p.ek]){
      element e1={a[p.ei+1]+b[p.ej]+c[p.ek], p.ei+1, p.ej, p.ek};
      PQ.push(e1);
      added[p.ei+1][p.ej][p.ek]=true;
    }
    if(p.ej+1<y && !added[p.ei][p.ej+1][p.ek]){
      element e2={a[p.ei]+b[p.ej+1]+c[p.ek], p.ei, p.ej+1, p.ek};
      PQ.push(e2);
      added[p.ei][p.ej+1][p.ek]=true;
    }
    if(p.ek+1<z && !added[p.ei][p.ej][p.ek+1]){
      element e3={a[p.ei]+b[p.ej]+c[p.ek+1], p.ei, p.ej, p.ek+1};
      PQ.push(e3);
      added[p.ei][p.ej][p.ek+1]=true;
    }
  }

  return 0;
}
