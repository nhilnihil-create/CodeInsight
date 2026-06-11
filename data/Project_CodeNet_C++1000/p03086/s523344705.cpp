#include <iostream>
#include <string>
using namespace std;
 
int main(void){
  string S;
  cin >> S;
  int ans = 0;
  int cnt = 0;
  for(int i = 0; i < S.size(); i++){
       if( S[i] == 'A' ||
           S[i] == 'C' ||
           S[i] == 'G' ||
           S[i] == 'T' ){
           cnt++;
       }else{
         if( ans < cnt ) ans = cnt;
         cnt=0;
       }
  }
  if( ans < cnt ) ans = cnt;
  cout << ans << endl;
}