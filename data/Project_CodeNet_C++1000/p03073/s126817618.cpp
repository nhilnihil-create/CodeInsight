#include <iostream>
#include <vector>
using namespace std;

int main(void){
   string s;
   cin >> s;
   if(s.size() == 1){
       cout << 0 << endl;
       return 0;
   }
   int ans = 0;
   if(s[0] == '1'){
       for(int i = 1;i < s.size();i++){
           if((i % 2 == 1 && s[i] == '1') ||
                (i % 2 == 0 && s[i] == '0')
            ){
               ans++;
           }
       }
   }else{
       for(int i = 1;i < s.size();i++){
           if((i % 2 == 1 && s[i] == '0') ||
              (i % 2 == 0 && s[i] == '1')
           ){
               ans++;
           }
       }
       
   }
   cout << ans << endl;
   
    return 0;
}
