#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;n>i;++i)
using namespace std;
using ll=int64_t;
using vi=vector<int>;
using VI=vector<ll>;
using vis=vector<string>;
using vvi=vector<vi>;
int gcd(int a,int b){
    if(a%b==0)
    return b;
    return gcd(b,a%b);
}
int main(){
    int a,b,k;
    cin>>a>>b>>k;
    int i=min(a,b),cnt=0,ans;
    while(cnt!=k){
        if(a%i==0&&b%i==0){
            ans=i;
            ++cnt;
        }
        --i;
    }
    cout<<ans<<endl;
}