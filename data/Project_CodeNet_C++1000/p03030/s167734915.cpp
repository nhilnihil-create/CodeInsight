#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

typedef struct shiranui {
    ll id, p;
    string s;
} flare;

int main(){
    ll n;
    cin >> n;
    vector<flare> a(n);
    rep(i, 0, n) {
        cin >> a[i].s >> a[i].p;
        a[i].id = i + 1;
    }
    sort(a.begin(), a.end(), [](flare l, flare r){
        if(l.s < r.s) return true;
        else if(l.s == r.s) return (l.p > r.p);
        else return false;
    });
    rep(i, 0, n) cout << a[i].id << endl;
    return 0;
}