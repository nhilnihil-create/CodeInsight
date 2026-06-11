#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;


int n;
string ans;

int main(){
  cin >> n;
  if(n == 0){
    cout << "0"<<endl;
    return 0;
  }
  while(n!=0){
    if(n%2){
      ans = "1" + ans;
      n--;
    }else{
      ans = "0" + ans;
    }
    n /= -2;
  }
  cout << ans <<endl;
}
  