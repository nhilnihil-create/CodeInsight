#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string s,t;cin>>s>>t;
    int matu  =s.length()-1;
    for(int i = 0;i<=1000;i++){
        char ss  =s[matu];
        char ms[matu+1];
        for(int j = 0;j<matu+1;j++) ms[j] = s[j];
        for(int k = 0;k<matu;k++){
        	s[k+1] = ms[k];
        }
        s[0] = ss;
    
        //cout<<s<<endl;
      if(s == t){
      	cout<<"Yes";
        return 0;
      }
    } 
    cout<<"No";
    return 0;
}