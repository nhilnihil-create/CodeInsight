#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const int INF = 1000000001;

int main(){
  char a, b;
  cin >> a >> b;
  if(a<b){
    cout << "<" <<endl; 
  }else if(a == b){
    cout << "=" <<endl;
  }else{
    cout << ">" <<endl;
  }
}