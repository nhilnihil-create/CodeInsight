#include<bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(int i=a;i<n;i++)
#define ve vector
#define ss second 
#define ff first
#define pf pop_front
#define pob pop_back
#define psf push_front
#define it vector<ll>:: iterator
#define res(x) cout<<x<<'\n'
#define read(t) ll t;cin>>t
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read(n);
    read(k);
    ll a[n];
    f(i,0,n)
    cin>>a[i];
    sort(a,a+n);
    bool dp[k+1];
    for(int i=0;i<=k;i++){
        dp[i]=0;
    }
   // dp[0]=1;
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i<a[j]){
                break;
            }
            else{
                if(!dp[i-a[j]]){
                    dp[i]=1;
                    break;
                }
            }
        }
    }
    if(dp[k]){
        cout<<"First";
    }
    else{
        cout<<"Second";
    }
    return 0;
    }