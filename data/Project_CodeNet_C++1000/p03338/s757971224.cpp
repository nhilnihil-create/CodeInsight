#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;cin>>N;
    string S;cin>>S;
    int ans=0;
    for(int i=1;i<N;i++){
        vector<int>A(26,0);
        vector<int>B(26,0);
        int tmp=0;
        for(int j=0;j<=i;j++){
            A[(int)S[j]-97]++;
        }
        for(int j=i+1;j<N;j++){
            B[(int)S[j]-97]++;
        }
        for(int j=0;j<26;j++){
            if(A[j]>=1&&B[j]>=1){
                tmp++;
            }
        }
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}
