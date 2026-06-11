#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    
string s;
cin>>s;

bool m1=false, m2=false;
//YYMM

if((s[0]=='0' && (s[1]>='1' && s[1]<='9'))|| 
    (s[0]=='1' && (s[1]=='1' || s[1]=='2')))
{
    m1=true;
}
    
if((s[2]=='0' && (s[3]>='1' && s[3]<='9'))|| 
    (s[2]=='1' && (s[3]=='1' || s[3]=='2'))){
    m2= true;
}
    

if(m1 && m2){
    cout<<"AMBIGUOUS";
}
else if(m1 || m2){
    if(m1){
        cout<<"MMYY";
    }else{
        cout<<"YYMM";
    }
}else{
    cout<<"NA";
}

    
    
}

    

