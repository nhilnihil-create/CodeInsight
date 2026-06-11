#include <bits/stdc++.h>
using namespace std;
int main() {
 int S;
 cin>>S;
bool a=false;
bool b=false;
if(0<S%100&&S%100<13){
    b=true;
}
if((S-S%100)/100<13&&0<(S-S%100)/100){
    a=true;
}
if(a==true&&b==true){
    cout<<"AMBIGUOUS"<<endl;
}
else if(b==true&&a==false){
    cout<<"YYMM"<<endl;
}
else if(b==false&&a==true){
    cout<<"MMYY"<<endl;
}
else
cout<<"NA"<<endl;
 }
