#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n,a,b;
  cin >> n >> a >> b;

  int q1 = 0;
  int q2 = 0;
  int q3 = 0;

  rep(i,n){
    int p;
    cin >> p;
    if(p >= b+1) q3++;
    else if(p >= a+1 && p <= b) q2++;
    else q1++;
  }
  cout << min(min(q1,q2),q3) << endl;
}
