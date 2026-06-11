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
    int a, b, c; cin >> a >> b >> c;
    int sum = 0;
    vector<int> s(3);
    s[0] = abs(a-b);
    s[1] = abs(b-c);
    s[2] = abs(a-c);
    sum += s[0] + s[1] + s[2];

    sort(all(s));

    cout << sum - s[2] << endl;
}