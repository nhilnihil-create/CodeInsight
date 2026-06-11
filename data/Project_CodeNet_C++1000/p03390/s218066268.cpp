#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REAP(i,a,n) for(int i=(a);i<(n);i++)
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define fr first
#define sc second
#define pb push_back
#define All(v) v.begin(),v.end()

bool check(ll ma,ll a,ll b){

    bool flg=true;
    for(ll i=ma/2-1000;i<=ma/2+1000;i++){
        if(i<1||i>ma)continue;
        ll x=i,y=ma-i+1;
        if(x>=a)x++;
        if(y>=b)y++;
        if(x*y>=a*b){
            flg=false;
        }
    }
    return flg;
}

ll solve(ll a,ll b){
    ll left = 0;
    ll right = a+b;
    while(right-left>1){
        ll mid = (left+right)/2;
        if(check(mid,a,b)){
            left=mid;
        }else{
            right=mid;
        }
    }
    return left;
}

int main(){
    int q;
    cin >> q;
    ll a,b,ans;
    while(q--){
        cin >> a >> b;
        ans = solve(a,b);
        cout << ans << endl;
    }
}
