#include <iostream>
using namespace std;
int main(void){
   string s;
   cin >> s;
   for(int i = 1;i < s.size();i++){
         if(s[i] != '9'){
               cout << s[0] - '0' - 1 + 9 * (s.size() - 1) << endl;
               return 0;
         }
   }
   cout << s[0] - '0' + 9 * (s.size() - 1) << endl;
   return 0;
}
