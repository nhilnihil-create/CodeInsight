#include <bits/stdc++.h>
using namespace std;

int main(void){
    int X;cin>>X;
    int ans=0;
    for(int i=1;i<=X;i++){
        for(int j=1;j<33;j++){
            for(int k=2;k<10;k++){
                if(i==pow(j,k)&&ans<pow(j,k)){
                    ans=pow(j,k);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}