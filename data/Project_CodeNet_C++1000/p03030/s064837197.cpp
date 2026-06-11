#include<bits/stdc++.h>
using namespace std ; 


int main(){
  char in[120];
  pair<pair<string,int>,int> p[110];
  
  int a;
  cin >> a;
  
  for(int i=0 ; i<a ; i++){
    int t;
    cin >> in >> t ;
    //string tmp = in;
    p[i] =make_pair(make_pair(in,-t),i);
  }

//sort(a, a+N); // 配列
//sort(ar.begin(), ar.end()); // array
//sort(v.begin(), v.end()); // vector
  
  sort(p,p+a);
  
  for(int i=0 ; i<a ; i++) {
    cout << p[i].second+1 << endl ;
  }
}