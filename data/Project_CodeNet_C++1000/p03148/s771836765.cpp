#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct S{
    int t, d;
    S(int t, int d) : t(t), d(d){}
    bool operator<(const S& s) const {
        if(d != s.d) return d > s.d;
        return t < s.t;
    }
};

int main() {
    int n, k;
    vector<S> ssh;
    long long ans = 0;
    cin >> n >> k;
    ssh.reserve(n);
    for(int i=0;i<n;i++){
        int t, d;
        cin >> t >> d;
        ssh.push_back(S(--t, d));
    }
    sort(ssh.begin(), ssh.end());
    long long sum = 0, srt = 0;
    vector<bool> usd(n, false);
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=0;i<k;i++){
        int t = ssh[i].t;
        int d = ssh[i].d;
        sum += d;
        if(usd[t]){
            q.push(d);
        }else{
            usd[t] = true;
            srt++;
        }
    }
    ans = sum + srt * srt;
    for(int i=k;i<n;i++){
        if(q.empty()) break;
        int t = ssh[i].t;
        int d = ssh[i].d;
        if(usd[t]) continue;
        int out = q.top(); q.pop();
        sum += d - out;
        usd[t] = true;
        srt++;
        long long tmp = sum + srt*srt;
        if(ans < tmp) ans = tmp;
    }
    cout << ans << endl;
	return 0;
}