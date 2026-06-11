#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
int main(){
    int N;
    cin>>N;
    
    bool f=false;
    for(int i=0;i<=N;i+=7){
        if((N-i)%4==0){
            f=true;
            break;
        }
    }
    
    cout<<(f?"Yes":"No")<<endl;
}
