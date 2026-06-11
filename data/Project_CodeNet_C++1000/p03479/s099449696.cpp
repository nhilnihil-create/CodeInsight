
#include <bits/stdc++.h>
using namespace std;
//#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
//srandom((unsigned long)time(NULL));

long long x,y;
cin>>x>>y;
long long shou=y;
long long ref=x;

for(long long i=1;i<=y/x;i++){
    ref=ref*2;
if(ref>shou){
    if(i==1){
        cout<<1<<endl;
        return 0;
    }
    cout<<i<<endl;
    return 0;
}

}


return 0;
}