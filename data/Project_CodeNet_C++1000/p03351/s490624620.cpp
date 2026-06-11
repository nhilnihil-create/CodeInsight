#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int a, b, c, d; cin >> a >> b >> c >> d;

    if((abs(a-b) <= d && abs(c-b) <= d) || abs(c-a) <= d ) cout << "Yes" << endl;
    else cout << "No" << endl;
}