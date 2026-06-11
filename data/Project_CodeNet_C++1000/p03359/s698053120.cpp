#include <bits/stdc++.h>
using namespace std;

int main(void){
   
 int a,b,c=0;
 cin >> a >> b;
 
 for(int i=1;i<=a;i++){
     c++;
     if(i == a && b < a) c--;
 }
 cout << c << endl;
}