#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#define __DEBUG__

using namespace std;
typedef long long ll;

int main(){
    int L;
    cin>>L;
    int N;
    int M;
    for(N = 0;(1<<N) <=L ;N++);
    M=2*(N-1);
    for(int i = 0;i < N-1;i++){
        if((L>>i)&1){
            M++;
        }
    }
    cout<<N<<" "<<M<<endl;
    for(int i = 0;i < N-1;i++){
        cout<<i+1<<" "<<i+2<<" "<<0<<endl;
        cout<<i+1<<" "<<i+2<<" "<<(1<<i)<<endl;
    }
    int newedge = 1<<(N-1);
    for(int i = 0;i < N-1;i++){
        if((L>>i)&1){
            cout<<i+1<<" "<<N<<" "<<newedge<<endl;
            newedge+=(1<<i);
        }
    }
}
