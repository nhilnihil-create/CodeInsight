#include <bits/stdc++.h>
using namespace std;

int main(void){
    
   string s,t;
   cin >> s >> t;
   int len = s.size();
   
   for(int i=0;i<len;i++){
       
       char last = s[len-1];
       for(int i=len-1;i>0;i--){
           s[i] = s[i-1];
       }
       s[0] = last;
       
       if(s == t){
           cout << "Yes" << endl;
           return 0;
       }
   
   }
   cout << "No" << endl;
}