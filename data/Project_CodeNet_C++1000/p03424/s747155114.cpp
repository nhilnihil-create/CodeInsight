#include <bits/stdc++.h>
using namespace std;
int main(){
 int n;
 cin >> n;
 string a;
 for(int i=0; i<n; i++){
   cin >> a;
   if(a=="Y"){
     cout << "Four" << endl;
     break;
   }
   else if (i==n-1)
     cout << "Three" << endl;
 }
   
  
}
