#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
   int n,t;cin>>n>>t;
   int ss =1000000;
   bool ikeru = false;
   for(int i = 0;i<n;i++){
      int c,tt;cin>>c>>tt;
      if(t >= tt){
        ss = min(ss,c);
        ikeru = true;
      }
   }
   if(ikeru == false) cout<<"TLE";
   else cout<<ss;
}