#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main() {
    int a,b;
    cin>>a>>b;
    if(a+b==15){
        cout<<'+'<<endl;
    }else if(a*b==15){
        cout<<'*'<<endl;
    }else{
        cout<<'x'<<endl;
    }
return 0;}
/*compile
g++ code.cpp
./a.out
run*/