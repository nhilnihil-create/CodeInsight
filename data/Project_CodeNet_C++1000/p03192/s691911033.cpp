#include <bits/stdc++.h>
using namespace std;

int main(){
   string s;
   cin >> s;
   int two=0;
   for(char c:s){
       if(c=='2'){
           two++;
       }
   }
   cout << two << endl;
}