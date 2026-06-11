#include<bits/stdc++.h>
using namespace std;

int main(){
    int A1,A2,A3;
    cin>>A1>>A2>>A3;
    int a = abs(A1-A2);
    int b = abs(A2-A3);
    int c = abs(A3-A1);
    cout<<a+b+c-max({a,b,c})<<endl;
    return 0;
}