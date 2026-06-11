using namespace std;
#include <bits/stdc++.h>
int main(){
    int a,b,e,s,x;cin>>a>>b;
    e=a-b;
    s=max(a+b,a*b);
    x=max(e,s);
    std::cout << x << std::endl;
    return 0;
}