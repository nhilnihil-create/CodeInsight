#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  int word = s.size();
  char min = 'a';
  
  
  if(word!=26){
    for(int i=0; i<26; i++){
      bool ans=true;
      for(int j=0; j<word; j++){
        if(s[j]==min){
          ans =false;
          min++;
          break;
        }
      }
      if(ans==true){
        cout << s << min << endl;
        return 0; 
      }
    }
  }

  else if(s=="zyxwvutsrqponmlkjihgfedcba"){
   cout << -1;
   return 0;
  }
  
  else{
   int back;

   for(int i=word-1; i>0; i--){
     if(s[i]>s[i-1]){
      min = s[i-1];
      back = i;
      break;
     }
   }
    
    for(int i=0; i<word; i++){
      for(int j=word-1; j>back-1; j--){
        if(min==s[j]){
         min = s[j];
         for(int i=0; i<back-1; i++){
        cout << s[i];
         }
          cout << min;
          return 0;
        }
      }
      min++;
    }
    
    
    
  }
  
  
}
