#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int N,K;    cin>>N>>K;
    vector<int> x(N,0);
    for(int i=0;i<N;i++){
        cin>>x[i];
    }
    int ans=999999999;
    for(int i=0;i+K<=N;i++){
        int l=x[i];
        int r=x[i+K-1];
        ans=min(ans,r-l+min(abs(l),abs(r)));
    }
    cout<<ans;
    return 0;
}