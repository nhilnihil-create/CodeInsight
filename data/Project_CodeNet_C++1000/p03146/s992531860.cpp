#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int s;cin>>s;
    int so = 0;
    if(s == 4||s==2||s==1){
      cout<<"4";
      return 0;
    }
    for(int i = 1;;i++){
      if(s%2 == 0) s=s/2;
      else s = 3*s+1;
      if(s == 4){
        so+= 1;
        if(so == 2){
          cout<<i+1;
          return 0;
        }
      }
    }
    return 0;
}