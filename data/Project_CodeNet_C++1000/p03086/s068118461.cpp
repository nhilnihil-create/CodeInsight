#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main() {
  // input
  string s; cin >> s;
 
  // compute
  int counter = 0;
  int max = 0;
  int ssize =s.size();
  
  for(int i =0; i < ssize; i++){
     bool a,c,g,t;
      a = (s.at(i) == 'A');
      c = (s.at(i) == 'C');
      g = (s.at(i) == 'G');
      t = (s.at(i) == 'T');
    
    if (a || c || g || t) {
        counter++;
         if(counter > max){
             max = counter;
         }
     }else{
         counter = 0;
     }
  }
 
  // output  
  cout << max << endl;
  
}