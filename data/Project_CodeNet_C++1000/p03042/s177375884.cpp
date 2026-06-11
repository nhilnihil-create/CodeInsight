#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string s;
    cin>>s;
    bool yy = false;
    bool mm = false;
    if(s[0] == '1'&&(s[1] == '0'||s[1] == '1'||s[1] == '2')){
      yy = true;
    }
    if(s[0] == '0'&&s[1]!='0') yy =true;
    if(s[2] == '1'&&(s[3] == '0'||s[3] == '1'||s[3] == '2')){
      mm = true;
    }
    if(s[2] =='0'&&s[3]!='0') mm =true;
    if(yy && mm ==false) cout<<"MMYY";
    if(yy == false&&mm) cout<<"YYMM";
    if(yy&&mm) cout<<"AMBIGUOUS";
    if(yy == false&&mm ==false) cout<<"NA";
    return 0;
}