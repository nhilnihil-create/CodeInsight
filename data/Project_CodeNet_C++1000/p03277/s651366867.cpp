#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 200001;

int n, fen[N];
vector <int> a;

void update(int ind, int val){
    ind++;
    while(ind <= 2 * n + 5){
        fen[ind] += val;
        ind += ind & -ind;
    }
}
int query(int ind){
    ind++;
    int ret = 0;
    while(ind >= 1){
        ret += fen[ind];
        ind -= ind & -ind;
    }
    return ret;
}
bool check(int m){
    vector <int> s;
    s.push_back(0);
    int cur = 0;
    for(int i = 0 ; i < n ; i++){
        cur += (a[i] >= m);
        s.push_back(2 * cur - (i + 1));
    }
    ll ret = 0;
    for(int i = 0 ; i < n + 1 ; i++){
        ret += query(s[i] + n);
        update(s[i] + n, 1);
    }
    for(auto &i : s){
        update(i + n, -1);
    }
    return 2 * ret >= 1LL * n * (n + 1) / 2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    int l = 1, r = 1e9;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << r << endl;
}
