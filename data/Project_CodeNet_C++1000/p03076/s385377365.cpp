#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> a(5);
  for(int i=0;i<5;i++){
    cin >> a[i];
  }
  
  vector<int> b(5);
  for(int i=0;i<5;i++){
    if(a[i]%10==0){
      b[i]=a[i];
    }
    else{
    b[i]=(a[i]/10+1)*10;
    }
  }
  
  vector<int> c(5);
  for(int i=0;i<5;i++){
    if(a[i]%10==0){
      c[i]=10;
    }
    else{
      c[i]=a[i]-a[i]/10*10;
    }
  }
  
  sort(c.begin(),c.end());
  
  int sum=0;
  for(int i=0;i<5;i++){
    sum += b[i];
  }
  
  sum -= 10-c[0];
  
  cout << sum << endl;
}