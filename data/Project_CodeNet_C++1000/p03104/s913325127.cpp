#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 1000000007

class Calc_Mod{//calculate mod
    public:
        unsigned int mod=1000000007;
        ll plus_mod(ll a,ll b){
            return (a+b)%mod;
        }
        ll minus_mod(ll a,ll b){
            return (a-b)%mod;
        }
        ll multi_mod(ll a,ll b){
            return a*b%mod;
        }
        ll LSM(ll a,int b){//a^b%mod
            queue<int> q;
            while(b>=1){
                q.push(b%2);
                b/=2;
            }
            ll ans=1;
            while(!q.empty()){
                if(q.front()==1){
                    ans=multi_mod(ans,a);
                }
                a=multi_mod(a,a);
                q.pop();
            }
            return ans;
        }
        ll div_mod(ll a,ll b){// a/b
            return multi_mod(a,LSM(b,mod-2));
        }
        ll combi(ll a,ll b){//aCb
            ll ans=1;
            ll kaijo=1;
            rep(i,b){
                ans=multi_mod(ans,a-i);
                kaijo=multi_mod(kaijo,b-i);
            }
            ans=div_mod(ans,kaijo);
            return ans;
        }
        
};

int main()
{
    ll a,b;
    cin >> a >> b;
    bool flag=false;
    bool flag_3=false;
    if(a%2==0){
        flag=true;
    }
    if(flag==false&&a!=1){
        flag_3=true;
    }
    ll num;
    int dist;
    ll ans;
    if(flag==true){
        num=(b-a)/4;
        num=a+4*num;
        ans=num;
        dist=(b-a)%4;
        rep(i,dist){
            ans^=(num+i+1);
        }
    }
    else{
        if(flag_3==false){
            num=(b-a)/3;
            num=a+3*num;
            dist=(b-a)%3;
            ans=num;
            rep(i,dist){
                ans^=(num+i+1);
            }
        }else{
            num=(b-a)/4;
            num=a+4*num;
            dist=(b-a)%4;
            ans=a;
            rep(i,dist){
                ans^=(num+i+1);
            }
        }

    }
    cout << ans << endl;
}