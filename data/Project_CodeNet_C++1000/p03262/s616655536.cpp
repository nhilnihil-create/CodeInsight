#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long int;
int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

int main(){
    long long int n,x;
    cin>>n>>x;
    vector<long long int>a(n);
    rep(i,n){
        long long int b;
        cin>>b;
        a[i]=abs(b-x);
    }
    sort(a.begin(),a.end());
    long long int ans=a[0];
    rep(i,n){
        ans=gcd(ans,a[i]);
    }
    cout<<ans<<endl;

}