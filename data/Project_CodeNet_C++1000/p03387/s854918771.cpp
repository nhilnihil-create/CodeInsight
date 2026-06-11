#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  vector<int> a(3);
  for(int i=0; i<3; ++i) cin >> a[i];

  sort(a.rbegin(), a.rend());
  int mx = a[0], mid = a[1];
  int dif = mx - mid;
  int cnt = 0;
  for(int i=0; i<dif; ++i){
    a[1]++;
    a[2]++;
    cnt++;
  }
  int dif2 = a[0] - a[2];
  if(dif2%2==1){
    a[0]++;
    a[1]++;
    cnt++;
  }
  int dif3 = a[0]-a[2];
  for(int i=0; i<dif3/2; ++i){
    a[2] += 2;
    cnt++;
  }
  cout <<cnt << endl;

}