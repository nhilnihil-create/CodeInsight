#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mmax=1000009;

int main(void){
    int n;
    cin>>n;
    vector<int> A(n);
    rep(i,n) cin>>A[i];
    long long ans=0;
    int right=0;
    long long sum=0,xsum=0;
    rep(left,n){
        while(right<n){
            sum+=A[right];
            xsum^=A[right];
            if(sum!=xsum){
                sum-=A[right];
                xsum^=A[right];
                break;
            }
            right++;
        }
        ans+=right-left;
        //printf("l=%d r=%d ans=%ld sum=%ld xsum=%ld\n",left,right,ans,sum,xsum);
        if(left==right) right++;
        else{
            sum-=A[left];
            xsum^=A[left];
        }
    }
    cout<<ans<<endl;
    return 0;
}
