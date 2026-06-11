#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int ans = 0;
int N;

void dfs(string now, bool t, bool f,bool s) {
    if(now!="" && stol(now) > N) return;
    if(t&&f&&s) ++ans;
    dfs(now+"3",true,f,s);
    dfs(now+"5",t,true,s);
    dfs(now+"7",t,f,true);
}

int main() {
    cin >> N;
    dfs("",false,false,false);
    cout << ans << endl;
}