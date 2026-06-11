//
//  main.cpp
//  ABC077A

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    char c[6]={};
    for(int i=0;i<6;i++){
        cin>>c[i];
    }
    string ans="YES";
    if(c[1]!=c[4]) ans="NO";
    if(c[0]!=c[5]) ans="NO";
    if(c[2]!=c[3]) ans="NO";
    cout<<ans<<endl;
    return 0;
}
