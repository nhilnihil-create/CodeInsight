#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;

bool isok(vector<int>& v) {
    for(int i = 1; i < v.size(); i++) {
        if(v[i] <= v[i-1]) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<pii> a, ans;
    for(int i = 0; i < N; i++) {
        int aa;
        cin >> aa;
        a.push_back(pii(aa, i+1));
    }   

    sort(a.begin(), a.end());
    if(a[0].first < 0) {
        pii p = abs(a[0].first) > abs(a[N-1].first) ? a[0] : a[N-1];
        for(int i = 0; i < N; i++) {
            ans.push_back(pii(p.second, i+1));
            a[i].first += p.first;
        }
    }

    if(a[N-1].first > 0) {
        for(int i = 1; i < N; i++) {
            ans.push_back(pii(i, i+1));
        }
    } else {
        for(int i = N - 1; i > 0; i--) {
            ans.push_back(pii(i+1, i));
        }        
    }

    cout << ans.size() << endl;
    for(auto e: ans) cout << e.first << " " << e.second << endl;

    return 0;
}
