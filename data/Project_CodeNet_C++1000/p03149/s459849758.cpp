#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int>N(10,0);
    N.at(a)=1;
    N.at(b)=1;
    N.at(c)=1;
    N.at(d)=1;
    if(N.at(1)+N.at(9)+N.at(7)+N.at(4)==4){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
return 0;}
/*compile
g++ code.cpp
./a.out
run*/