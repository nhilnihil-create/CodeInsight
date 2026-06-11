#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());

typedef long long ll;

int main(){
  int a,b;
  cin >> a >> b;
  int c = b - a;
  vector<int> d(999);
  vector<int> e(999);
  d[0] = 1;
  for(int i=1;i<999;i++) d[i] = d[i-1]+i+1;
  for(int i=1;i<999;i++){
    if(d[i]-d[i-1] == c){
      cout << d[i-1]-a << endl;
    }
  }
}