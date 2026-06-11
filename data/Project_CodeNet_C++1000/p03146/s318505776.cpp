#include<bits/stdc++.h>
using namespace std;

int main (){
  int s;
  cin >> s;
  
  vector<int> a(1000000);
  
  a[0]= s;
  
  for (int i;i<1000000;i++){
    if(a[i]%2==0){
      a[i+1] = a[i]/2;
    }
    else{
      a[i+1] = 3*a[i]+1;
    }
    
    for (int j =0;j< i+1;j++){
      if (a[j] == a[i+1]){
        cout << i+2 << endl;
        return 0;
      }
    }
  }
}