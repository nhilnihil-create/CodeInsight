#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename K,typename V>
using umap = unordered_map<K,V>;
template <typename V>
using uset = unordered_set<V>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i,n) for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(v) v.begin(),v.end()

#define INF 1'000'000'000'000 //10^12
#define MOD 1'000'000'007

int main(){

    int n,m;

    cin >> n;

    int d[n];

    map<int,int> count;

    REP(i,n){
        cin >> d[i];

        count[d[i]]++;
    }

    cin >> m;
    int t[m];
    REP(i,m){
        cin >> t[i];

        if(count[t[i]]>0){
            count[t[i]]--;
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
