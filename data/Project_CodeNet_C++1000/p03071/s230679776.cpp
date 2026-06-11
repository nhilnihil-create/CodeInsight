#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, x=0;
    cin>>a>>b;
    if(a>b){
        x=a+(a-1);
    }
    else if(a==b){
        x=a+b;
    }
    else{
        x=b+(b-1);
        }
    cout<<x;
}