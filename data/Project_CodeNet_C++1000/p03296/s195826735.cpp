#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define scan(n,v) v.resize(n); rep(i,n){ cin>>v[i];}
#define MOD 1000000007ll
#define Yes(flag) cout<<((flag)? "Yes":"No");
#define YES(flag) cout<<((flag)? "YES":"NO");
#define be begin
#define pb push_back
#define fi first
#define se second
#include<bits/stdc++.h>
using ll = long long;
using namespace std;
template<class T>T 
chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T>T 
chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
//------------------------------------------------------
int n;
vector<int> a;
void input(){
    cin>>n;
    scan(n,a);
}
void src(){
    int count=0;
    int eq=0;
    rep(i,n-1){
        if(a[i]==a[i+1]){
            eq++;
        }else{
            count += (eq+1)/2;
            eq=0;
        }
    }
    count += (eq+1)/2;
    eq=0;
    cout<<count;
}   
int main(int argc,char* argv[]){
    ios::sync_with_stdio(false);
 //   ifstream in( argv[1] ); cin.rdbuf(in.rdbuf());
    input();
    src();    
    return 0;
}