#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  int n, m, x;
  cin >> n >> m >>x;
  vector<int> a(m);
  int cnt=0, cnt1=0;
  for(int i=0; i<m; ++i) cin >> a[i];
  for(int i=0; i<m; ++i){
    if(a[i]<x) cnt++;
    else if(a[i]>x) cnt1++;
  }

  cout << min(cnt, cnt1) <<endl;


  return 0;
}