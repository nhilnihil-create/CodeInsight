#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll INF=1000000000;
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,1,-1,0,1,-1,0};
ll digitsum(ll n){
    ll sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
bool f[100010];
int main(){
    vector<ll> v;
    ll s=1;
    for(ll i=0;i<15;i++){
        for(ll j=2;j<=150;j++){
            v.push_back(s*j-1);
        }
        s*=10;
    }
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            double a=(double)v[i]/(double)digitsum(v[i]);
            double b=(double)v[j]/(double)digitsum(v[j]);
            if(a>b){
                f[i]=true;
            }
        }
    }
    int k;cin>>k;
    int c=0;
    for(int i=0;i<v.size();i++){
        if(c==k)break;
        if(f[i])continue;
        cout<<v[i]<<endl;
        c++;
    }   
}