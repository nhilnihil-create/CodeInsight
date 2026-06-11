#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int N, C;

struct show {
    int s;
    int t;
    int c;

    bool operator<(const show& other) const {
        if (c < other.c) return true;
        if(c > other.c) return false;
        return s < other.s;
    }
};

bool cmp(const show & a, const show & b) {
    return a.s > b.s; 
}

bool check(int recorders, vector<vector<show> >& shows_channel, set<int>& times, int min_t, int max_t) {
    
    for(int t: times) {
        int duplicates = 0;
        REP(c, C) {
            show tmp = {t, 0, c};
            auto itr = lower_bound(shows_channel[c].rbegin(), shows_channel[c].rend(), tmp, cmp);
            if(itr != shows_channel[c].rend() && (*itr).t >= t) {
                // cerr << "t = " << t << " show: c=" << (*itr).c << " s=" << (*itr).s << " t=" << (*itr).t << endl;
                duplicates++;
            }
        }
        if(duplicates > recorders) return false;
    }

    return true;
}

int main() {
    cin >> N >> C;

    vector<int> s, t, c, channel_last(C);
    vector<show> shows_input(N);
    REP(i, N) {
        int s_tmp, t_tmp, c_tmp;
        cin >> s_tmp >> t_tmp >> c_tmp;
        shows_input[i].s = s_tmp;
        shows_input[i].t = t_tmp;
        shows_input[i].c = c_tmp - 1;
        
    }

    sort(shows_input.begin(), shows_input.end());

    vector<show> shows;

    int idx_tail = -1, min_start = 2e5, max_terminate = 0;
    REP(i, N) {
        show tmp = {shows_input[i].s, shows_input[i].t, shows_input[i].c};

        if(min_start > tmp.s) min_start = tmp.s;
        if(max_terminate < tmp.t) max_terminate = tmp.t;

        if(i>0 && tmp.s == shows[idx_tail].t && tmp.c == shows[idx_tail].c) {
            shows[idx_tail].t = tmp.t;
        } else {
            shows.push_back(tmp);
            idx_tail++;
        }
    }
    N = idx_tail + 1;

    set<int> times;
    REP(i, N) {
        times.insert(shows[i].s);
        times.insert(shows[i].t);
    }

    vector< vector<show> > shows_channel(C, vector<show>());
    REP(i, N) {
        shows_channel[shows[i].c].push_back(shows[i]);
    }

    REP(c, C) {
        sort(shows_channel[c].begin(), shows_channel[c].end());
        // reverse(shows_channel[c].begin(), shows_channel[c].end());
    }

    int lower_bound = 0, upper_bound = 30;
    while(lower_bound < upper_bound-1) {
        bool flag = check((upper_bound+lower_bound)/2, shows_channel, times, min_start, max_terminate);
        if(flag) upper_bound = (upper_bound+lower_bound)/2;
        else lower_bound = (upper_bound+lower_bound)/2;
    }

    cout << upper_bound << endl;

    return 0;
}