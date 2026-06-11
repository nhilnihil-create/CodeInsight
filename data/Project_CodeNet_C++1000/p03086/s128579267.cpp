#include <bits/stdc++.h>
using namespace std;

int main(void){
        
   string s;
   int max = 0,count = 0;
   cin >> s;
   int len = s.size();
   
   for(int i=0;i<len;i++){
       if(s[i] != 'A' && s[i] != 'C' && s[i] != 'G' && s[i] != 'T') s[i] = ' ';
   }
   
   for(int i=0;i<len;i++){
       
       if(s[i] != ' '){
           count++;
       }
       else{
           if(max < count) max = count;
           count = 0;
       }
       
       if(i == len-1){
           if(max < count) max = count;
       }
   }

   cout << max << endl;
}