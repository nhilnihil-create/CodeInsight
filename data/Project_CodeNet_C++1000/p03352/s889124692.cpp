#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(n) begin(n),end(n)

int main(){
    int x;
    cin>>x;

    int ans=1;
    for(int i=2; i<=sqrt(x); i++){
        for(int j=2; j<1000; j++){
            if(pow(i,j)>x){
                break;
            }
            if(pow(i,j)>ans){
                ans=pow(i,j);
            }
        }
    }

    cout<<ans<<endl;
}