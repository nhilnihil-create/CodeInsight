#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(b>a*c)cout<<c<<endl;
    else cout<<b/a<<endl;
    return 0;
}