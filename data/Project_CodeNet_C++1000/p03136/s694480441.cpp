#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n; cin >>n;
  vector<int> l(n);
  for(int i=0; i<n; ++i){
    cin >> l[i];
  }

  sort(l.rbegin(), l.rend());

int sum = 0;
  for(int i=1; i<n; ++i){
    sum += l[i];
  }
  if(l[0]<sum) cout << "Yes" << endl;
  else cout << "No" << endl;
}  
