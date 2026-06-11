#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
    int N,A,B;
    cin>>N>>A>>B;
    if(A+B<=N){
        cout<<min(A,B)<<" "<<0<<endl;
    }else{
        cout<<min(A,B)<<" "<<A+B-N<<endl;    
    }
    //cout<<min(A,B)<<" "<<A+B-N<<endl;
return 0;}
/*compile
g++ code.cpp
./a.out
run*/
/*
int f(int x){
    int y=int((x*x+4.0)/8.0);
    return y;
}
*/
