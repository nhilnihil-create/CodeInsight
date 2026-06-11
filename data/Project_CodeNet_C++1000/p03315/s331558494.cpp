#include<bits/stdc++.h>
using namespace std;

int i,r=0;
string a;


int main(){
    cin>>a;
    for(i=0;i<=a.length();i++){
        if(a[i]=='+'){
            r=r+1;
        }
        else if(a[i]=='-'){
            r=r-1;
        }
    }
    cout<<r;
}