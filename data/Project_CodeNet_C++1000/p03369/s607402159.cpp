#include <iostream>
using namespace std;
int main(void){
string s;
int  y,ss=0;
cin>>s;
if(s[0]=='o'){
    ss++;
}
if(s[1]=='o'){
    ss++;
    }
if(s[2]=='o'){
    ss++;
}
y=(ss*100)+700;
cout<<y<<endl;
}