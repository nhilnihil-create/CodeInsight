#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
ll gcd(ll a,ll b){
    ll m = min(a,b);
    ll M = max(a,b);
    if(M%m==0){
        return m;
    }else{
        return gcd(m,M%m);
    }
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
int main(){
    int n,x;
    cin >> n>>x;
    vector<int> data(n+1);
    rep(i,0,n){
        cin >> data[i];
    }
    data[n]=x;
    sort(data.begin(),data.end());    
    vector<int> diff(n+10);
    rep(i,0,n){
        diff[i]=data[i+1]-data[i];
        //cout<<diff[i]<<endl;
    }
    int now = diff[0];
    rep(i,0,n){
        now = gcd(now,diff[i]);
    }
    cout<<now<<endl;

  return 0;
}