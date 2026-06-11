#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

using Graf_char=vector<vector<char>>;
using Graf_int=vector<vector<int>>;
#define MAX 10000000

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    rsort(a);
    ll point_a=0;ll point_b=0;
    rep(i,n){
        if(i%2==0){
            point_a+=a[i];
        }else{
            point_b+=a[i];
        }
    }
    cout << point_a-point_b << endl;

}