#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
           int n;
           cin >>n;

    vector<double> vec(n);
    for (int i = 0; i < n; i++) {
        cin>> vec.at(i);
    }
     
    double ave=0;
  for(int i=0;i<n;i++){
  ave += vec[i];
  }
  ave = ave / n;
  double k=10000;
  bool A=false;
  int c=0;
  for(int i=0;i<n;i++){
   
 if(k <= abs(ave - vec[i]) ){
    continue;
    }
    
    if(k >  abs(ave - vec[i])){
  k=min(abs(ave - vec [i]),k);
      c=i;
      
    }
  }
  cout <<c<<endl;
}
