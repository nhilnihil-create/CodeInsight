/// Kazuki Hoshino


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pi> vpi;
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define f first
#define ss second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
#define endl '\n'

ll n, x[202020], v[202020], c, mx[202020], ans, rev[202020], val[101010], rval[101010];


int main(){
ios::sync_with_stdio(0);
cin.tie(0);

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);


cin >> n >> c;

rep(i, 1, n){

    cin >> x[i] >> v[i];

}


rep(i, 1, n){

    mx[i] = val[i-1]+v[i] - x[i];
    val[i]=val[i-1]+v[i];

}


rep(i,1, n){

    mx[i] = max(mx[i-1], mx[i]);
    ans = max(ans, mx[i]);

}



rep1(i, n, 1){

    rval[i]+=rval[i+1]+v[i];
    ll temp = -2*(c-x[i]) + rval[i];
    ans = max(ans, temp + mx[i-1] );
    //cout << temp + mx[i-1] << endl;

}

rep1(i, n, 1){
    mx[i]=0;
    val[i]=0;
    mx[i] = val[i+1]+v[i] - (c-x[i]) ;
    val[i] = val[i+1]+v[i];
    //cout << mx[i] << " " << val[i] << endl;
}

rep1(i, n, 1){

    mx[i] = max(mx[i+1], mx[i]  );
    ans = max(ans, mx[i]);

}

rep(i, 0, n){

    rval[i]=0;
    rval[i]=rval[i-1]+v[i];
    ll temp = rval[i] - 2*x[i];
    ans = max(ans , temp+mx[i+1]);
    //cout << temp + mx[i] << endl;
}

cout << ans << endl;

return 0;}
///....
