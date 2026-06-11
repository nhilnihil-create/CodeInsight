#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1001001001;
const ll MOD = 1e9 + 7;
const double PI = 3.14159265358979;


int main(){
  int a, b;
  string s;
  cin >> a >> b >> s;
  if(int(s.size()) == a + b + 1 && s[a] == '-'){
    rep(i, a+b+1){
      if(i == a) continue;
      if(!isdigit(s[i])){
        cout << "No" <<endl;
        return 0;
      }
    }
    cout << "Yes" <<endl;
    return 0;
  }
  cout << "No"<<endl;
}