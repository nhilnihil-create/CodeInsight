#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<ll>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define INF 117117117117117

int main()
{
    ll n;
    vector<ll> num(5);
    cin >> n >> num[0] >> num[1] >> num[2] >> num[3]>>num[4];
    ll min;
    ssort(num);
    min=num[0];
    ll times=n/min;
    if(n%min!=0){
        times++;
    }
    cout << times+4 << endl;
}