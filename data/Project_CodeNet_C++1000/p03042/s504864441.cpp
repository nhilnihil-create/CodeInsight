#include <bits/stdc++.h>
using namespace std;

int main(){
   int s;
   cin >> s; 
   int a = s/100;
   int b = s%100;
   if(12>=a && 12>=b && a!=0 && b!=0){
      cout << "AMBIGUOUS" << endl;
   } 
   else if(12>=a && a!=0){
      cout << "MMYY" << endl;
   }
   else if(12>=b && b!=0){
      cout << "YYMM" << endl;
   }
   else{
      cout << "NA" << endl;
   }
}