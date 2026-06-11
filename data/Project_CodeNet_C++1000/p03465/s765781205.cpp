#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;
const int MAX_N=4000001;

int main(){
    
    int N;cin>>N;
    vector<int> A(N);
    int sum=0,right;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    }
    right=sum/2;
    bitset<MAX_N> dp;
    dp[0]=1;
    
    for(int i=0;i<N;i++){
        dp |= (dp << A[i]);
    }
    
    for(int i=right;i>=0;i--){
        if(dp[i]){
            cout<<sum-i<<endl;
            break;
        }
    }
    
}
