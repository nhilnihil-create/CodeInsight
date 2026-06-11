#include <iostream>
using namespace std;
 
int main() {
	string s;
    cin>>s;
    for(int i=0;i<s.length();i=i+1){
    	if(s[i]=='1')
    		cout<<'9';
    	else 
      		cout<<'1';
    }
    return 0;
}