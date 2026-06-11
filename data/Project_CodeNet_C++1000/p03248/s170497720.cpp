#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=100000000000000000;

int main() {
    string s;
    cin >> s;
    int n=s.size();
    if (s.at(n-1)=='1' || s.at(0)=='0') {cout << -1 << endl;return 0;}
    rep(i,n/2){
        if (s.at(i)!=s.at(n-2-i)) {cout << -1 << endl;return 0;}
    }
    s.at(n-1)='1';
    vector<int> a(0);
    rep(i,n){
        if (s.at(i)=='1') a.push_back(i+1);
    }
    rep(i,n-1){
        auto it=upper_bound(all(a),i+1);
        cout << i+1 << " " << *it << endl;
    }
}
