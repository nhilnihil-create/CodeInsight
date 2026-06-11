#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int n; cin >> n;
  vector<int> a(100009,0), b(100009,0);
  int v;
  rep(i,n){
    cin >> v;
    if (i%2) b[v]++;
    else a[v]++;
  }
  
  ll retval;
  int argmax_a = max_element(all(a)) - a.begin();
  int argmax_b = max_element(all(b)) - b.begin();
  if (argmax_a!=argmax_b) retval = n - a[argmax_a] - b[argmax_b];
  else {
    sort(all(a), greater<int>());
    sort(all(b), greater<int>());
    retval = min(n-a[0]-b[1],n-a[1]-b[0]);
  }

  cout <<retval << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}
