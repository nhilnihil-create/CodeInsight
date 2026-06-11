#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"Yes"<<endl
#define cno cout<<"No"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;

ll A(ll n,ll a,ll b){
    return n*a*b;
}
ll B(ll n,ll a,ll b){
    return 4*a*b - (a+b)*n;
}

int main(){

    ll N; cin >> N;
    ll h,n,w;
    for(ll a = 1; a <= 3500; a++)for(ll b = 1; b <= 3500; b++){
        if(B(N,a,b)<=0) continue;
        if(A(N,a,b) < B(N,a,b)) continue;
        if(A(N,a,b)%B(N,a,b) == 0){
            h = a;
            w = b;
            n = A(N,a,b)/B(N,a,b);
            break;
        }
    }    
    cout << h sp w sp n << endl;
    return 0;
}
