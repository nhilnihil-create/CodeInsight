#include <bits/stdc++.h>
using namespace std;

int yakusu(int x){
    int y=1;
    for(int a=3;a*a<=x;a+=2){
        if(x%a==0){
            y++;
        }
    }
    return y;
}

int main(void){
    // Your code here!
    int N;cin>>N;
    int count,ans;count=ans=0;
    for(int i=1;i<=N;i+=2){
        if(yakusu(i)==4){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
