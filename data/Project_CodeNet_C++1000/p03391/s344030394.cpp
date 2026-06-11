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
#define inf 1000000000000000
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define f first
#define ss second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
#define endl '\n'

ll n, a[202020], b[202020], dif=inf, sum , ans=inf;


int main(){
ios::sync_with_stdio(0);
cin.tie(0);

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);


cin >> n;

rep(i, 1, n){
cin >> a[i] >> b[i];
if(a[i]>b[i])ans = min(ans, b[i] );
sum+=a[i];
}

if(ans==inf){
    cout << 0 << endl;
}
else {
    cout << sum-ans << endl;
}







return 0;}
///....
