#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S;cin>>S;
    int ans=753;
    for(int i=0;i<S.size()-2;i++){
        string tmp;
        tmp=S.substr(i,3);
        int X=abs(stoi(tmp)-753);
        if(ans>X){
            ans=X;
        }
    }
    cout<<ans<<endl;
    return 0;
}