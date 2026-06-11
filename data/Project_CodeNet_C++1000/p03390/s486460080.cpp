#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 10000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

#define no {cout<<"No"<<endl; continue;}
#define yes {cout<<"Yes"<<endl; continue;}

int gcd(int a,int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

signed main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    rep(i,n){
        int a,b; cin>>a>>b;
        if(a>b)swap(a,b);
        if(a==b)cout<<2*a-2<<endl;
        else if(a+1==b)cout<<2*a-2<<endl;
        else{
            int c=floor(sqrt(a*b));
            if(c*c==a*b)c--;
            if(c*(c+1)>=a*b)cout<<2*c-2<<endl;
            else cout<<2*c-1<<endl;
        }
    }
    
}