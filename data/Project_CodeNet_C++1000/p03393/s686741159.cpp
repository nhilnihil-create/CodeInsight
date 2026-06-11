//Diverse Word

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
using p = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    string s;cin>>s;
    map<char,int>m{};
    rep(i,0,s.size())m[s[i]]++;
    if(s.size()<26){
        char t;
        for(char i='a';i<='z';i++){
            if(m[i]==0){
                s.pb(i);
                break;
            }
        }
        cout<<s<<nnn;
    }else{
        string t = s;
        if(!next_permutation(range(s))){
            cout<<-1<<nnn;
            return 0;
        }
        bool flag = true;
        for(int i=0;flag;i++){
            cout<<s[i];
            if(s[i]!=t[i])flag = false;
        }
        cout<<nnn;
    }
    return 0;
}