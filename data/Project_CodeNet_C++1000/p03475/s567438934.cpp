#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

vector<int> c, s, f;
int n;
vector<int> ans;

void gotoN(int pos){
    int now = s[pos];
    for(int i = pos; i < n-1; i++){
        now = now + c[i];
        if(i == n-2) break;
        if(now <= s[i+1]) now = s[i+1];
        else {
            if(now % f[i+1] == 0) continue;
            else now += (f[i+1] - now%f[i+1]);
        }
    }
    ans.push_back(now);
}

int main(){
    cin >> n;
    c.resize(n-1), s.resize(n-1), f.resize(n-1);
    rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
    rep(i,n-1) gotoN(i);
    ans.push_back(0);
    for(auto elem : ans) cout << elem << endl;
}