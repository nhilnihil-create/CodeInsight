#include <bits/stdc++.h>
using namespace std;
int main(){
   string S;
   cin >> S;
   int ans = 700;
   for(int i = 0; i < S.length(); i++){
       if(S[i]=='o') ans+=100;
   }
    cout << ans << endl;  
    return 0;
}