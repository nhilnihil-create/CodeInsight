#include<bits/stdc++.h>
using namespace std;


int main(){
  int d[4];
  for(int i=0;i<3;++i){
    d[i]=0;
  }
  for(int i=0;i<3;++i){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    d[a]++;
    d[b]++;
  }
  if(d[0]<=2 && d[1]<=2 && d[2]<=2  && d[3]<=2){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}
