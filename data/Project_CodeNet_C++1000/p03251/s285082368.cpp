#include<bits/stdc++.h>
#define VI vector<int>
#define VVI vector<vector<int>>
#define REP(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n), b(m);
    REP(i,n)cin >> a[i];
    REP(i,m)cin >> b[i];
    a.push_back(x), b.push_back(y);
 
    int nax = *max_element(a.begin(), a.end());
    int niy = *min_element(b.begin(), b.end());
 
    cout << (niy > nax ? "No War" : "War") << endl;
}

