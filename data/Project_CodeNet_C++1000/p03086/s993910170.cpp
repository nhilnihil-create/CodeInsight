#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    string S;cin>>S;
    int ans=0;
    int tmp=0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='A'||S[i]=='C'||S[i]=='G'||S[i]=='T'){
            tmp++;
        }
        else{
            if(ans<tmp){
                ans=tmp;
            }
            tmp=0;
        }
        if(ans<tmp){
            ans=tmp;
        }
    }
    cout<<ans<<endl;
    return 0;
}