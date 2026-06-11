#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s,t;
  cin >> s >> t;
  
 for(int i = 0; i < static_cast<int>(s.size()); i++){
   for(int j = static_cast<int>(s.size())-1; j > i; j--){
     if(s.at(j) < s.at(j-1)){
       char tmp = s.at(j-1);
       s.at(j-1) = s.at(j);
       s.at(j) = tmp;
     }
   }
 }
  
  for(int i = 0; i < static_cast<int>(t.size()); i++){
   for(int j = static_cast<int>(t.size())-1; j > i; j--){
     if(t.at(j) > t.at(j-1)){
       char tmp = t.at(j-1);
       t.at(j-1) = t.at(j);
       t.at(j) = tmp;
     }
   }
 }
 
  if(s < t){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
}