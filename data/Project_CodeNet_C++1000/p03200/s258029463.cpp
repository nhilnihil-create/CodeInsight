#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    string S;cin>>S;
    long long count=0;
    long long ans=0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='W'){
            ans+=i-count;
            count++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
