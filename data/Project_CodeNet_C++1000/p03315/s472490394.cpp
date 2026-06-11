#include<bits/stdc++.h>
using namespace std;
int main(void){
string s;cin>>s;
int x = 0;
char a[5];
strcpy(a,s.c_str());
cout<<count(a,a+4,'+')-count(a,a+4,'-')<<endl;
return 0;}
