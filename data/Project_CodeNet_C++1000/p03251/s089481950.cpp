#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  int a[n],b[m];
  int d=9999,e=-9999;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]>e)e=a[i];
  }
  for(int i=0;i<m;i++){
    cin >> b[i];
    if(b[i]<d)d=b[i];
  }
  for(int i=e+1;i<=d;i++){
    if(x<i&&i<=y){
      cout << "No War" << endl;
      return 0;
    }
  }
  cout << "War" << endl;
}
