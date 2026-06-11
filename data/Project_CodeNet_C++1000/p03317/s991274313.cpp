#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N,K;
    cin>>N>>K;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    double ans=ceil((double)(N-1)/(double)(K-1));
    cout<<ans<<endl;
    return 0;
}

