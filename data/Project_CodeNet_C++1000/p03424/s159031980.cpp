#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int i=0,n,p=0,y=0,w=0,g=0;
  cin>>n;
  
  
  while(i<n){
    string a;
    cin>>a;
    
    if(a=="G"&&g==0){      
        g++;
      }      
     else if(a=="P"&&p==0){      
        p++;
      }       
     else if(a=="W"&&w==0){
        w++;
      }       
     else if(a=="Y"&&y==0){
        y++;
      }
       
      i++;            
     }
              
   if(p+g+y+w==3){
         cout<<"Three"<<endl;
       }
   else if(p+g+y+w==4){
         cout<<"Four"<<endl;
       }           
}