#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n;
  cin >> n;
  string in[120];
  pair<pair<string,int>,int> p[110];
  for(int i=0; i<n; ++i){
    int t;
    cin >> in[i] >> t;
    p[i] = make_pair(make_pair(in[i],-t),i);
  }
  sort(p,p+n);
  for(int i=0; i<n; i++) cout << p[i].second+1 << endl;

}