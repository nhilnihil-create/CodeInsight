#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n;
  cin >> n;
  double ans=0.0;
  for(int i=0; i<n; i++){
    double x;
    string s;
    cin >> x >> s;
    if(s=="JPY") ans += x;
    else ans += x*380000.0;
  }
  cout << ans << endl;
  return 0;
}
