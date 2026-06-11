#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long N,A_sum,B_sum,m,ans;
int main(){
    cin>>N;
    vector<long long>A(N),B(N),C(N),ok;
    for(int i=0;i<N;i++){cin>>A[i];A_sum+=A[i];}
    for(int i=0;i<N;i++){cin>>B[i];B_sum+=B[i];}
    if(A_sum<B_sum){cout<<-1<<endl;return 0;}
    for(int i=0;i<N;i++)C[i]=A[i]-B[i];
    for(int i=0;i<N;i++){
        if(C[i]>=0)ok.emplace_back(C[i]);
        else m+=C[i],ans++;
    }
    if(m>=0){cout<<0<<endl;return 0;}
    sort(ok.begin(),ok.end(),greater<long long>());
    for(auto x:ok){
        m+=x;
        ans++;
        if(m>=0){cout<<ans<<endl;return 0;}
    }
    return 0;
}