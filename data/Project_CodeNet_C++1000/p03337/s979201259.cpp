#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;

    auto result = max({a+b, a-b, a*b});
    cout<<result;

    return 0;
}