#include<bits/stdc++.h>
using namespace std;
int main(){
string a;
long double b,s=0.000000;
int c;
cin>>c;
while(c--){
    cin>>b>>a;
    if(a[0]=='J')
        s=s+b;
    else{
        s=s+(b*380000.0);
    }

}
cout<<s<<endl;
return 0;}
