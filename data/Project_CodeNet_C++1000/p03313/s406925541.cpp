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

ll n, a[1<<19], temp , t = 1,mx[1<<19];
pll ans[1<<19], res[1<<19] ;

void add(int x, int y){
    vi v;
    v.pb(ans[x].first);
    v.pb(ans[x].second);
    v.pb(ans[y].first);
    v.pb(ans[y].second);
    sort(all(v));
    reverse(all(v));
    ans[x].first = v[0];
    ans[x].second = v[1];
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);


cin >> n;

rep(i, 0, (t<<n)-1 ){

    cin >> a[i];
    ans[i].f = a[i];
    //ans[i].ss = a[0];

    if(ans[i].ss > ans[i].f){
        swap(ans[i].ss , ans[i].f);
    }

}


rep(i, 0, n){

    rep(j, 0, (t<<n)-1){

    if(j & (t<<i))continue;
    else temp = j|(t<<i);
    add( temp, j );
    /*
    if(ans[temp].ss<=a[j]){
        ans[temp].ss = a[j];
        if(ans[temp].f < ans[temp].ss){
            swap(ans[temp].f, ans[temp].ss);
        }
    }
    */
    }

}
/*
rep(i, 0, n){

    rep(j, 1, (t<<n)-1 ){

    if(j<(t<<i) ){
        mx[j] = max( mx[j-1], ans[j].f + ans[j].ss) ;
    }

    }

}
*/
ll pree = ans[0].first+ans[0].second;
rep(i, 1, (1<<n)-1){
pree = max(pree, ans[i].first+ans[i].second );
//cout << ans[i].f << " " << ans[i].ss << endl;
//cout << max( ans[i].f + ans[i].ss ,  mx[i]) << endl ;
cout << pree << endl;
}





return 0;}
///....
