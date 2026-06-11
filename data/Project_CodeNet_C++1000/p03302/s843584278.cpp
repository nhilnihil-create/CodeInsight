#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
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
//typedef tuple<ll, ll, ll> T;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void add(ll& a, ll b){a = (a+b) % MOD;}

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    if(a+b==15) cout<<'+';
    else if(a*b==15) cout<<'*';
    else cout<<'x';
}