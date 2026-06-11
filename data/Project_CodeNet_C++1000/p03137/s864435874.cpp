#include <bits/stdc++.h>
#define pb push_back
#define Int int64_t
using namespace std;

int N,M,A,B,C,K;
int main()
{
    cin>>N>>M;
    vector<Int> A(M);
    for(auto &x:A) cin>>x;
    Int sum=0;
    sort(A.begin(),A.end());
    vector<Int> diff;
    for(int i=1;i<M;++i){
        sum=A[i]-A[i-1];
        diff.pb(sum);
    }
    sort(diff.begin(),diff.end());
    Int ans=accumulate(diff.begin(),diff.end(),0);
    int j=diff.size();int k=0;
    for(int i=j-1;i>=0&&k<N-1;--i,++k) ans-=diff[i];
    cout<<ans<<"\n";
}