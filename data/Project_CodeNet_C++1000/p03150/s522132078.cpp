#include <bits/stdc++.h>
using namespace std;

int main(){
    string A="keyence";
    string S;cin>>S;
    int a=S.size()-7;
    bool ans=0;
    for(int i=0;i<7;i++){
        string SS = S;
        SS.erase(i,a);
        if(A==SS){
            ans=1;
            break;
        }
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}