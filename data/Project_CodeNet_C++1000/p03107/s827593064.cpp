#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    string S;cin>>S;
    long long r,b;r=b=0;
    for(long long i=0;i<S.size();i++){
        if(S[i]=='0'){
            r++;
        }
        else{
            b++;
        }
    }
    cout<<min(r,b)*2<<endl;
    return 0;
}
