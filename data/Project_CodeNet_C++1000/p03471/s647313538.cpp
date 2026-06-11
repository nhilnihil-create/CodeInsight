#include <bits/stdc++.h>
using namespace std;


int main() {
 int N, Y, k;
  cin >> N >> Y;
  
  string a = "no";
  
  if(Y%1000==0){
  
  for(int i=Y/10000;i>=0;i--){
    for(int j=(Y-10000*i)/5000;j>=0;j--){
      k= (Y-10000*i-5000*j)/1000;
        if(i+j+k==N){
          cout << i <<" " <<j <<" " << k <<endl;
          a="Yes";
          break;
        }
    }
  if(a=="Yes")break;
  }
  }
    
  if(a=="no"){
    cout <<-1 <<" " << -1 << " " << -1 <<endl;
  }
}
  