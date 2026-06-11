#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int N,K; cin>>N>>K;
    vector<int> A(N+1,0);
    for(int i=0;i<N;i++){
        int a; cin>>a;
        A[a]++;
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    int count=0;
    int ans=0;
    for(int i=0;i<=N;i++){
        if(count<K){
            count++;
        }
        else{
            ans+=A[i];
        }
    }
    cout<<ans;
    return 0;
}