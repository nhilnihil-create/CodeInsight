#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,m,c,i,j,s,ac;
  cin >> n >> m >> c;
  vector<int> a(m),b(m);
  for(i=0;i<m;i++){
    cin >> b.at(i);
  }
  
  ac=0;
  for(j=0;j<n;j++){
    s=0;
    for(i=0;i<m;i++){
      cin >> a.at(i);
      s += a.at(i)*b.at(i);
    }
    if(s+c>0){
      ac++;
    }
  }
  
  cout << ac << endl;
}