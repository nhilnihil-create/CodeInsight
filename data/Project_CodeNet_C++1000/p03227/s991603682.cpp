#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main() {
    string S;
    cin>>S;
    if(S.size()==2){
        cout<<S<<endl;
    }else{
        cout<<S.at(2)<<S.at(1)<<S.at(0)<<endl;
    }
return 0;}
/*compile
g++ code.cpp
./a.out
run*/