#include<iostream>
using namespace std;

int main(){
    int s;
    cin>>s;
    int b=s%100;
    int f=s/100;
    string ans="NA";
    if(b<=12&&f<=12&&b>0&&f>0) ans="AMBIGUOUS";
    else if(b<=12&&(f>12||f==0)&&b>0) ans="YYMM";
    else if((b>12||b==0)&&f<=12&&f>0) ans="MMYY";
    cout<<ans<<endl;
}
