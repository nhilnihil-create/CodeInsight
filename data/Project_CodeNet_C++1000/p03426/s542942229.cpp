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
    int h,w,d;
    cin >> h >> w >> d;
    vector<P> a(h*w+1);
    int num;
    rep(i,h){
        rep(j,w){
            cin >> num;
            a[num]=mp(i+1,j+1);
        }
    }
    
    int q;
    cin >> q;
    vector<P> task(q);
    rep(i,q){
        cin >> task[i].first >> task[i].second;
    }
    vector<ll> power(q);
    int val,val_r;
    vector<ll> dist(h*w+1,0);
    rep(i,d+1){
        dist[i]=0;
    }
    FOR(i,h*w+1,d+1){
        int k=a[i-d].first;
        int l=a[i-d].second;
        int x=a[i].first;
        int y=a[i].second;
        dist[i]=dist[i-d]+(abs(x-k)+abs(y-l));
    }
    rep(i,q){
        val=task[i].first;
        val_r=task[i].second;
        power[i]=dist[val_r]-dist[val];
    }
    rep(i,q){
        cout << power[i] << endl;
    }

}