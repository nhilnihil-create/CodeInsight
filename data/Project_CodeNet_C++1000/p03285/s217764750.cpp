#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while((n%4!=0&&n%   7!=0)&&(n>=11)){
        n-=11;
    }
    if(n%4==0||n%7==0){
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
}