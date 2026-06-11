//c++ テンプレ
#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define reverse(v) reverse(v.begin(),v.end())
#define count(v,x) count(v.begin(),v.end(),x)
#define find(v,x) find(v.begin(),v.end(),x)


priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int calc(int x){
    int ret=0;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            ret++;
            if(x/i!=i)ret++;
        }
    }
    return ret;
}


void solve(){
    int n;
    cin >> n;
    int ans=0;
    for(int i=1;i<=n;i+=2){
        if(calc(i)==8)ans++;
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}


