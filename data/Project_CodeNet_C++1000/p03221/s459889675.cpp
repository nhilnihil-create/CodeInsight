#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int N = 1000000;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * B / gcd(A, B);
}

/*------------------------------------------------------------------*/
string push0(int m){
    string re = "";
    rep(i, m) re += '0';
    return re;
}
int main(){
    int n, m; cin >> n >> m;
    vector<tuple<int,int,int>> p;
    rep(i, m){
        int a, b; cin >> a >> b;
        p.emplace_back(a, b, i);
    }
    sort(p.begin(), p.end());
    vector<pair<int,string>> ans(m);
    int count = 1;
    rep(i, m){
        if(i > 0){
            if(get<2>(p[i - 1]) < get<0>(p[i])){
                count = 1;
            }else{
                count++;
            }
        }
        swap(get<0>(p[i]), get<2>(p[i]));
        string a = to_string(get<2>(p[i]));
        string b = to_string(count);
        if(a.size() < 6) a = push0(6 - a.size()) + a;
        if(b.size() < 6) b = push0(6 - b.size()) + b;
        ans[i].first = get<0>(p[i]);
        ans[i].second = a + b;
    }
    sort(ans.begin(), ans.end());
    rep(i, m) cout << ans[i].second << endl;
    return 0;
}