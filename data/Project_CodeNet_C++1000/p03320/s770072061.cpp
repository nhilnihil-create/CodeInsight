#include<iostream>
#include<algorithm>
#include<string>
#include<utility>
#include<queue>
#include<set>

using namespace std;

set<long long> candidates;
priority_queue< pair<long double, long long> > snuke;

void push_candidates() {
    for(int i=1;i<=136;++i) {
        int d = (i<10 ? 15 : (i<100 ? 14 : 13));
        long long candidate = (long long)i;
        candidates.insert(candidate);
        if(i == 1) continue;
        candidate *= 10LL;
        for(int j=1;j<=d;j++) {
            candidates.insert(candidate-1);
            candidate *= 10LL;
            if(candidate > 1e15) break;
        }
    }
}

void calc() {
    for(long long candidate: candidates) {
        
        string s = to_string(candidate);
        long double sum = 0;
        for(int i=0;i<s.length();i++) {
            sum += (long double)(s[i] - '0');
        }
        // cerr << candidate/sum << " " << candidate << endl;
        snuke.emplace(-candidate/sum, -candidate);
    }
}

int main(){
    int K;
    cin >> K;
    push_candidates();
    calc();

    long long min_ = 0;
    int cnt = 0;
    while(cnt < K) {
        pair<long double, long long> p = snuke.top(); snuke.pop();
        // cerr << p.first << " " << p.second << endl;
        while(-p.second < min_) {
            p = snuke.top();
            // cerr << p.first << " " << p.second << endl;
            snuke.pop();
        }
        min_ = -p.second;
        cout << -p.second << endl;
        cnt++;
    }
}