#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;

int main(){
  int n;
  cin >> n;
  vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  int a = 0, b = 0, c = 0, d = 0, e = 0;
  for(int x : prime){
    int tmp = 0;
    int y = x;
    while(n >= y){
      tmp += n / y;
      y = y * x;
    }
    if(tmp >= 74) e++;
    if(tmp >= 24) d++;
    if(tmp >= 14) c++;
    if(tmp >= 4) a++;
    if(tmp >= 2) b++; 
  }
  cout << a * (a-1)/2 * (b-2) + e + d * (b-1) + c * (a-1) << endl;
    
}