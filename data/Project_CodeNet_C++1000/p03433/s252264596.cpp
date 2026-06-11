#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int total;
  int onecoin;
  int amari;

  
  cin >> total >> onecoin ;
  
  amari = total % 500;
  if(amari <= onecoin){
    cout << "Yes"<<endl;
    
  }
  
  else{
  
    cout << "No" << endl;
  
  }
  
}
  
