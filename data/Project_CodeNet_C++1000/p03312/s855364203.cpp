#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <array>
#include <bitset>
using namespace std;

typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<n+1;i++)

ll mini(ll *A,int N,int s1,int s2,int s3){
    if(s2==s1 || s2==s3 || s1==0) return A[N];
    ll m=A[N],M=0;
    M=max(M,A[s1]); m=min(m,A[s1]);
    M=max(M,A[s2]-A[s1]); m=min(m,A[s2]-A[s1]);
    M=max(M,A[s3]-A[s2]); m=min(m,A[s3]-A[s2]);
    M=max(M,A[N]-A[s3]); m=min(m,A[N]-A[s3]);
    return M-m;
}

int main(){
    int N;
    ll A[200001],a;
    cin>>N;
    A[0]=0;
    Rep(i,N) {
        cin>>a;
        A[i]=A[i-1]+a;
    }
    ll ans=A[N];
    int s1=1,s2=2,s3=3;
    while(s2<N-1){
        s3=max(s3,s2+1);

        while(true){
            if(s2-s1==1 || A[s1]>A[s2]/2) break;
            s1++;
        }
        while(true){
            if(N-s3==1 || A[s3]-A[s2]>(A[N]-A[s2])/2) break;
            s3++;
        }
        ans=min(ans,mini(A,N,s1,s2,s3));
        ans=min(ans,mini(A,N,s1-1,s2,s3));
        ans=min(ans,mini(A,N,s1,s2,s3-1));
        ans=min(ans,mini(A,N,s1-1,s2,s3-1));
        s2++;
    }
    cout<<ans<<endl;
    return 0;
}