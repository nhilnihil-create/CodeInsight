#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string S;
    long long K;cin>>S>>K;
    for(long long i=0;i<K;i++){
        if(S[i]!='1'){
            cout<<S[i]<<endl;
            return 0;
        }
    }
    cout<<1<<endl;
    return 0;
}
