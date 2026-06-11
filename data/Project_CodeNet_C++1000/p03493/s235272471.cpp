#include<bits/stdc++.h>

using namespace std;

int main(){
    string g ;
    cin>>g;

    int ans=0;

    for(int i=0;i<=2;i++){
        if (g[i]=='1'){
            ans+=1;
        }
    }
    cout << ans;
    return 0;
}
