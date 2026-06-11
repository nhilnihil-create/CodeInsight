#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string s; cin>>s;
    int k1 = 0;
    int k2 = 0;
    for(int i= 0;i<s.length();i++){
      if(i%2==0){
      	if(s[i] =='1') k1+=1;
        else k2+=1;
      }
      else{
      	if(s[i] == '0')k1+=1;
        else k2+=1;
      }
    }
    cout<<min(k1,k2);
    return 0;
}