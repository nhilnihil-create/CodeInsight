#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
int main(void){
    // Your code here!
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int cnt;
    cnt=0;
    rep(i,n+1)rep(j,n+1){
        int q,m;
        q=(n-i*r-j*g)/b;
        m=(n-i*r-j*g)%b;
        if(q>=0 && m==0)cnt++;  
    }
    cout<<cnt<<endl;
}
