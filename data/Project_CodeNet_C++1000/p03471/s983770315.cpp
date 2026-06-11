#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    int N,Y,k;
    bool flag=false;
    cin>>N>>Y;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N-i;j++){
            k=N-i-j;
            if(Y==10000*i+5000*j+1000*k){
                flag=true;
                cout<<i<<" "<<j<<" "<<k;
                break;
            }
        }
        if(flag)break;
    }
    if(!flag)cout<<-1<<" "<<-1<<" "<<-1;
}