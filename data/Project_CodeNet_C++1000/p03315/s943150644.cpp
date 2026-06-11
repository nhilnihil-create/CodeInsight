#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string s;cin>>s;
    int res = 0;
    for(int i=0;i<4;++i){
        if(s.at(i)=='+') ++res;
        else --res;
    }
    cout<<res;
}