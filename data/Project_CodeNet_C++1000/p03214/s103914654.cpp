#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int main(){
    int N;
    cin >> N;
    int v[100];
    int s[101];
    int c = 0;
    double t = 0;
    rep(i, 101) {
        s[i] = 0;
    }
    rep(i, N){
        int res;
        cin >> res;
        t += res;
        if (s[res] == 0) {
            v[c] = res;
            s[res] = i+1;
            c++;
        }
    }

    t /= (double)N;

    sort(v, v+c);
    int res;
    rep(i, N){
        if (t <= v[i]) {
            res = i;
            break;
        }
    }

    if (res >= 1) {
        if (abs((double)v[res-1] - t) < abs((double)v[res] - t)) {
            cout << s[v[res-1]] - 1 << endl;
        } else if (abs((double)v[res-1] - t) > abs((double)v[res] - t)){
            cout << s[v[res]] - 1 << endl;
        } else {
            cout << min(s[v[res-1]], s[v[res]]) - 1 << endl;
        }
    } else {
        cout << s[v[res]] - 1 << endl;
    }

}