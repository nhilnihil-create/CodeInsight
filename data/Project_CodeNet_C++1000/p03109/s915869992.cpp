#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string s;cin>>s;
    if(s[6] <= '4'&&s[5] != '1') cout<<"Heisei";
    else cout<<"TBD";
  	
    return 0;
}