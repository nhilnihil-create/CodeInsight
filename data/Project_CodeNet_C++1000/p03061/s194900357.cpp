#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,a[100005],gl[100005],gr[100005];
ll G;
ll gcd(ll a,ll b){
    if(b%a==0) return a;
    else return gcd(b%a,a);
}
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    gl[1]=a[0];
    gr[1]=a[n-1];
    for(int i=2;i<=n;i++){
        gl[i]=gcd(gl[i-1],a[i-1]);
        gr[i]=gcd(gr[i-1],a[n-i]);
    }
    G=max(gr[n-1],gl[n-1]);
    for(int i=1;i<n-1;i++){
        G=max(G,gcd(gl[i],gr[n-i-1]));
    }
    cout<<G<<endl;

}
