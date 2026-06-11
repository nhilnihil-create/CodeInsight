#include <iostream>
 using namespace std;
 int main(){
     int n;
     cin>>n;
 if(n==25)cout<<"Christmas";
 if(n!=25){
     int m= 25-n;
     string s="Eve ";
      string s1 = s;
     for(int i=1;i<m;i++){
         s+=s1;
     }
     cout<<"Christmas"<<" "<<s;
 }
 
 }