#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;
typedef tuple<ll, ll, ll> T;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    ll ma=0;
    int ma_idx;
    REP(i,n){
        int a;
        cin>>a;
        if(abs(ma)<abs(a)) ma = a,ma_idx=i;
    }
    ma_idx++;
    cout<<2*n-1<<endl;
    for(int i=1;i<=n;i++){
        cout<<ma_idx<<" "<<i<<endl;
    }
    if(ma>=0){
        for(int i=1;i<n;i++) cout<<i<<" "<<i+1<<endl;
    }
    else{
        for(int i=n;i>1;i--) cout<<i<<" "<<i-1<<endl;
    }
}