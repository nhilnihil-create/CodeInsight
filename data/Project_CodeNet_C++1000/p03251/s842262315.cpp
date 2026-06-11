#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;

  vector<int> x(n), y(m);
  for(int i=0; i<n; ++i) cin >> x[i];
  for(int i=0; i<m; ++i) cin >> y[i];

  sort(x.rbegin(), x.rend());
  sort(y.begin(), y.end());

  int diff = y[0] - x[0];
  int num = x[0];
  bool flag = false;
  for(int i=0; i<diff; ++i){
   num++;
   if(X < num && num < Y) flag = true;
   else{
     flag = false;
     break;
   }
  }
  if(flag) cout << "No War" << endl;
  else cout << "War" << endl;

}
