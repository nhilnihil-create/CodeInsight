#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int a, b; cin >> a >> b;
    int idx  = b - a;
    int height = 0;
    for(int i = 1; i < idx; ++i) height += i;
    cout << height - a << endl;
}