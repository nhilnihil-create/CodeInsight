#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
int main(void){
    // Your code here!
   string vec;
    cin>>vec;
   
   int ans=0;
   for(int i=0;i<(1<<3);i++){
       ans=vec[0]-'0';
       string out;
       out+=vec[0];
       for(int j=0;j<3;j++){
           if(1<<j & i){
             ans+=vec[j+1]-'0';
             out+='+';
             out+=vec[j+1];
           }else{
               ans-=vec[j+1]-'0';
               out+='-';
               out+=vec[j+1];
           }
       }
       if(ans==7)
       {
           out+="=7";
        cout<<out;  
        break;
       }
   }
}
