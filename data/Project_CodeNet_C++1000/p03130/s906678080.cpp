#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a(3),b(3),c(4);
  for(int i=0;i<3;i++){
    cin >> a[i] >> b[i];
    c[a[i]-1]++;
    c[b[i]-1]++;
  }
  bool t=true;
  for(int i=0;i<4;i++){
    if(c[i]==3){
      t=false;
    }
  }
  if(t){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}