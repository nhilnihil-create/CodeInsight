#include <bits/stdc++.h>
using namespace std;

int main() {

  int n , c ,p , w , g , y ;
    cin >> n;
    string s ;
    c = 0;
    p = 0;
    w = 0;
    g = 0;
    y = 0;
    
    for (int j = 0; j < n; j++) {
       
      cin  >> s ;
      
      if (s == "P" && p == 0){
         c ++;
         p = 1 ;
      }
   
      if (s == "W" && w ==0){
         c  ++ ;
         w = 1 ;
      }
      
      if (s == "G" && g == 0){
         c ++;
         g = 1 ;
     } 
      if (s == "Y" && y == 0){
         c ++;
         y = 1 ;
     }
     
    }
  
    if(c==3){
        cout << "Three"<< endl;
    }
    else if(c==4){
        cout << "Four" << endl;
   
  }
  }