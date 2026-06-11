#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
    int N,K;
    cin>>N>>K;
    if(N%2==0){
        if(N/2>=K){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{
        if((N/2)+1>=K){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
return 0;}
/*compile
g++ code.cpp
./a.out
run*/