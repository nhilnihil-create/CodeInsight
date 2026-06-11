#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  double n, t, a;
  cin >> n >> t >> a;
  double diff = 1000000;
  int ans = 0;
  for(int i=0; i<n; i++){
    double h;
    cin >> h;
    if(diff>abs(a-(t-h*0.006))){
      diff = abs(a-(t-h*0.006));
      ans = i+1;
    }
  }
  cout << ans << endl;
  return 0;
}
