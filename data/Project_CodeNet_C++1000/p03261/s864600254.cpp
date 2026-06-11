#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define rep11(i, n) for (int i = 1; i < (int)(n); ++i)
#define repo(i, o, n) for (int i = o; i < (int)(n); ++i)
#define repm(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1002000007
#define INF LONG_LONG_MAX
typedef pair<long long, long long> P;
int main(){
    long long n;
    cin>>n;
    vector<string> w(n);
    rep(i,n){
        cin>>w[i];
    }
    set<string> p;
    p.insert(w[0]);
    char g=w[0][w[0].size()-1];
    rep11(i,n){
        if(g!=w[i][0]){
            cout<<"No"<<endl;
            return 0;
        }
        g=w[i][w[i].size()-1];
        if(p.find(w[i])!=p.end()){
            cout<<"No"<<endl;
            return 0;
        }
        p.insert(w[i]);
    }
    cout<<"Yes"<<endl;
    return 0;
}