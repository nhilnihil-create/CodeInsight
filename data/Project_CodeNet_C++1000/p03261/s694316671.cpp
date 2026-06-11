#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n;cin>>n;
    string s[n];
    for(int i = 0;i<n;i++) cin>>s[i];
    char matu = s[0][s[0].length()-1];
    for(int i = 1;i<n;i++){
      if(matu ==s[i][0]){
      	 matu = s[i][s[i].length()-1];
      }
      else{
         cout<<"No";
         return 0;
      }
    }
    sort(s,s+n);
    for(int i =0;i<n-1;i++){
       if(s[i] == s[i+1]){
         cout<<"No";
         return 0;
       }
    }
    cout<<"Yes";
    return 0; 
}