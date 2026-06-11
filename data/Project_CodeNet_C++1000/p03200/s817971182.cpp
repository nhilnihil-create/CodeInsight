#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin>>S;
    int N=S.size();
    int B[N];
    long long count=0;
    B[0]=0;
if(N>=1&&N<=2*100000){
    if(S[0]=='B'){
        B[0]+=1;
    }
    else{
        B[0]=0;
    }
    for(int i=1;i<N;i++){
        B[i]=B[i-1];
        if(S[i]=='B')
            B[i]+=1;
    }
    for(int i=0;i<N;i++){
        if(S[i]=='W'){
        count+=(i-1>=0?B[i-1]:0);
    }
    }
    cout<<count;
}
    return 0;
}