//Exam and Wizard

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, string>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n;cin>>n;
    vecrep(n,a,int);
    vecrep(n,b,int);
    vector<int>ama;
    rep(i,0,n){
        if(a[i]>b[i])ama.pb(a[i]-b[i]);
    }
    sort(range(ama),greater<int>());
    int aac = accumulate(range(a),0LL);
    int bac = accumulate(range(b),0LL);
    if(aac<bac){
        cout<<-1<<nnn;
        return 0;
    }
    int ans = 0;
    int tari = 0;
    rep(i,0,n){
        if(a[i]<b[i]){
            tari+=b[i]-a[i];
            ans++;
        }
    }
    for(int i = 0;tari>0;i++){
        tari-=ama[i];
        ans++;
    }
    cout<<ans<<nnn;
    return 0;
}