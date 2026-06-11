//755

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define YN(flag) (flag?"Yes":"No")
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

set<int>ans;

bool chk(string t){
    bool c[3] = {false,false,false};
    rep(i,0,t.size()){
        if(t[i]=='7')c[0]=true;
        else if(t[i]=='5')c[1]=true;
        else if(t[i]=='3')c[2]=true;
    }
    if(c[0]&&c[1]&&c[2])return true;
    else return false;
}

void dfs(string s,int keta,string n){
    if(s.size()==keta)return;
    char c[3] = {'7','5','3'};
    rep(i,0,3){
        string t = s;
        t.pb(c[i]);
        if(stoi(t)<=stoi(n)){
            if(chk(t)){
                ans.insert(stoi(t));
            }
            dfs(t,keta,n);
        }
    }
}

signed main (){
    string n;cin>>n;
    int keta = n.size();
    string s = "";
    dfs(s,keta,n);
    cout<<ans.size()<<nnn;
    return 0;
}