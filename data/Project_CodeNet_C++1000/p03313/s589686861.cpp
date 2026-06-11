#include <bits/stdc++.h>

#define ll long long
#define ff first
#define ss second
#define pb push_back

using namespace std;

const int N = 1e6+69, mod = 1e9+9;

ll n,m,x,y,a,b,c,d,t,k,ans=1e18,cur,l,r;

ll A[N],dp[N],mx[N],mx1[N];

int main() {
    
    cin>>n;
   
    for(int i=0;i<(1<<n);i++)
        cin>>A[i];
    
    if(A[0]<A[1]){
        mx[1] = 1;
        mx1[1] = 0;
    } else {
        mx[1] = 0;
        mx1[1] = 1;
    }
    dp[1] = A[0]+A[1];
    mx[0] = 0;
    
    for(int i=2;i<(1<<n);i++){
        
        mx[i] = i;
        
        for(int j=0;j<n;j++)
        if( (i>>j) & 1){
            //cout<< (i^(1<<j)) <<endl;
            if(A[mx[i]] <= A[ mx[i^(1<<j)] ] && mx[i] != mx[i^(1<<j)] ){
                mx1[i] = mx[i];
                mx[i] = mx[i^(1<<j)];
            } else 
            if(A[mx1[i]] < A[ mx[i^(1<<j)] ] && mx1[i] != mx[i^(1<<j)] 
                                             && mx[i] != mx[i^(1<<j)]) {
                mx1[i] = mx[i^(1<<j)];
            }
        }
        
        dp[i] = max(A[mx[i]] + A[mx1[i]],dp[i-1]);
        //cout<<mx[i]<<" "<<mx1[i]<<" "<<i<<endl;
        
    }
    
    for(int i=1;i<(1<<n);i++)
    cout<<dp[i]<<" ";
   
}
