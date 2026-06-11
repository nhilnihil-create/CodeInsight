#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    char a,b;
    cin>>a>>b;
    int x,y;
    x=a-'0';
    y=b-'0';
    if(x>y)cout<<">";
    else if(x==y)cout<<"=";
    else cout<<"<";
}
