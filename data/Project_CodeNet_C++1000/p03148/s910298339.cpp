#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

struct Sushi {
    int t = -1;
    int d = -1;
};

bool operator<(const Sushi &a, const Sushi &b) {
    return a.d < b.d;
}

bool operator>(const Sushi &a, const Sushi &b) {
    return a.d > b.d;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    priority_queue<Sushi> td;
    priority_queue<Sushi, vector<Sushi>, greater<Sushi>> std;
    map<int, int> tm;
    ll answer = 0, basic = 0, bonus;
    
    rep(i, n) {
        Sushi tmp;
        cin >> tmp.t >> tmp.d;
        td.push(tmp);
    }
    
    rep(i, k) {
        Sushi s = td.top();
        basic += s.d;
        tm[s.t]++;
        std.push(s);
        td.pop();
    }
    
    bonus = (ll)sz(tm) * sz(tm);
    answer = basic + bonus;
    
    while (sz(td) > 0) {
        Sushi ts, ss;
        bool f = false;
        
        ts = td.top();
        td.pop();
        
        if (tm.count(ts.t) > 0) {
            continue;
        }
        
        while(sz(std) > 0) {
            ss = std.top();
            std.pop();
            
            if (tm[ss.t] > 1) {
                f = true;
                break;
            }
        }
        
        if (!f) {
            break;
        }
        
        tm[ss.t]--;
        tm[ts.t]++;
        bonus = (ll)sz(tm) * sz(tm);
        basic += ts.d - ss.d;
        
        answer = max(answer, basic + bonus);
    }
    
    cout << answer << endl;
    return 0;
}
