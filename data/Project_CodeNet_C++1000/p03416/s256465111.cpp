#include <bits/stdc++.h>
using namespace std;

int main(void){
    int A,B;cin>>A>>B;
    int ans=0;
    for(int i=A;i<=B;i++){
        string X=to_string(i);
        int tmp=0;
        for(int l=0;l<2;l++){
            if(X[l]==X[4-l]){
                tmp++;
            }
        }
        if(tmp==2){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}