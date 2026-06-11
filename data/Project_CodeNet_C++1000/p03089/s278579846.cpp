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
  int N; cin >> N;
  vector<int> b(N); rep(i,N) cin >> b[i];
  
  vector<int> a(N);
  bool possible = true;
  for (int i=N-1;i>=0;i--){
    bool check = false;
    for (int j=i;j>=0;j--){
      if (b[j]==j+1){
        a[i] = b[j];
        b.erase(b.begin()+j);
        check = true;
        break;
      }
    }
    if (check==false) {
      possible = false;
      break;
    }
  }
  if (possible==false) cout << -1 << endl;
  else {
    rep(i,N) cout << a[i] << endl;
  }




  // cout << fixed << setprecision(10);
  
  return 0;
}
