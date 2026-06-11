#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n, m;
  cin >> n >> m; 
  int left = 1; int right = n;
  for(int i=0; i<m; ++i){
    int a, b;
    cin >> a >> b;
    left = max(left, a);
    right = min(right, b);
  }

  cout << max(right -left + 1, 0) << endl;
  return 0;
}