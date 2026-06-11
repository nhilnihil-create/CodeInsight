#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const ll mod=pow(10,9)+7;
const ll INF=pow(2,31)-1;
typedef pair<int,int> P;
typedef vector<int> vi;

ll gcd(ll a,ll b){
    ll v0=a,v1=b,v2=a%b;
    while(v2!=0){
        v0=v1;
        v1=v2;
        v2=v0%v1;
    }
    return v1;
}

ll lcm(ll a,ll b){
    return (a*b/gcd(a,b));
}

int main(){
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<int> a;
    int keta;
    int ff=0;
    if(n<=9) cout << n <<endl;
    else{
        while(n){
        a.push_back(n%10);
        n/=10;
        keta++;
    }

    rep(i,a.size()-1){
        if(a[i]==9) ff++;
    }
    int ans=9*(keta-1);
    if(ff==keta-1) ans+=a.back();
    else ans+=a.back()-1;
    cout << ans << endl;
    }
    return 0;
}
