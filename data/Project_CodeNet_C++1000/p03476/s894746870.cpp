//2017-like Number

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, string>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

bool IsPrime(int num){
    if(num<2)return false;
    else if(num==2)return true;
    else if(num%2==0)return false;
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0)return false;
    }
    return true;
}

signed main (){
    vector<int>t(100010,false);
    rep(i,1,100010)if(IsPrime(i))if(IsPrime((i+1)/2))t[i]=true;
    vector<int>s(100010,0);
    rep(i,1,100010){
        if(t[i]){
            s[i]=s[i-1]+1;
        }
        else s[i]=s[i-1];
    }
    int q;cin>>q;
    rep(i,0,q){
        int l,r;cin>>l>>r;
        cout<<s[r]-s[l-1]<<nnn;
    }
    return 0;
}