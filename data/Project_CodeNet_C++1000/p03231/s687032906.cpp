#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

ll gcd(ll x,ll y){return y ? gcd(y,x%y) : x;};
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
int main(){
    int N,M;cin>>N>>M;
    string s,t;
    cin>>s>>t;
    int g=gcd(N,M);
    REP(i,g){
        if(s[i*(N/g)]!=t[i*(M/g)]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<lcm(N,M)<<endl;
}
