#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
   string s;
   cin >> s;
   for(int i=0;i<s.size();i++){
       for(int j=0;j<=s.size();j++){
           string t = s;
           if(t.erase(i,j)=="keyence"){
               cout << "YES" << endl;
               return 0;
           } 
       }
   }
   cout << "NO" << endl;
}