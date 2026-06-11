#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
 }

ll lcm(ll a, ll b)  {
    return (a*b)/gcd(a, b);
}

ll fact(ll n){
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}

void solve(){

    ll N,M;
    cin>>N>>M;
    ll A[N][M],i,j;
    char c;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin>>c;
            if(c=='.')
                A[i][j] = 0;
            else
                A[i][j] = -1;
        }
    }

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(A[i][j]%mod==-1)
                continue;
            if(i==0 && j==0){
                A[i][j] = 1;
            }
            else if(i==0){
                A[i][j] = A[i][j-1]%mod;
            }
            else if(j==0){
                A[i][j] = A[i-1][j]%mod;
            }
            else{
                if(A[i-1][j]%mod==-1)
                    A[i][j] = A[i][j-1]%mod;
                else if(A[i][j-1]%mod==-1)
                    A[i][j] = A[i-1][j]%mod;
                else
                    A[i][j] = (A[i-1][j]%mod + A[i][j-1]%mod)%mod;
            }
        }
    }
    /*for(i=0;i<N;i++){
        for(j=0;j<M;j++)
            cout<<A[i][j]<<" ";
        cout<<"\n";
    }*/
    ll k = A[N-1][M-1]%mod;
    if(k<0)
        cout<<0;
    else
        cout<<k%mod;

}

int main(){
    //freopen("D:\\codes\\1input.txt","r",stdin);
    //freopen("D:\\codes\\1output.txt","w",stdout);
    ll T=1;
    //cin>>T;
    for(ll t=1;t<=T;t++){

        //cout<<"Case #"<<t<<": ";
        solve();
        //cout<<"\n";
    }
}
