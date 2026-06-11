#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>b)a=b;
    if(c>d)c=d;
    cout<<a+c<<endl;
    return 0;
}