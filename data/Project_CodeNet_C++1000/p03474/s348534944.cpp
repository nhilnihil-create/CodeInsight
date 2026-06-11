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
  int A, B; cin >> A >> B;
  bool flag = true;
  rep(i,A+B+1){
    char c; cin >> c;

    if (i<A && isdigit(c)) continue;
    else if (i==A && c=='-') continue;
    else if (i>A && isdigit(c)) continue;
    else {
      flag = false;
    }
  }

  cout << (flag ? "Yes" : "No") << endl;


  // cout << fixed << setprecision(6);
  return 0;
}
