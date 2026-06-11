#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int N, C;
    cin >> N >> C;
    vector< vector< pair<int,int> > > channel(C);
    while(N--) {
        int s, t, c;
        cin >> s >> t >> c;
        channel[--c].emplace_back(s, t);
    }

    vector<int> time(100000);
    for(auto c: channel) {
        sort(c.begin(), c.end());
        for(int i=1; i<c.size(); i++) {
            if(c[i-1].second == c[i].first) {
                c[i].first = c[i-1].first;
                c[i-1].second = c[i-1].first - 1;
            }
        }
        for(int i=0; i<c.size(); i++) {
            ++time[c[i].first - 1];
            --time[c[i].second];
        }
    }

    partial_sum(time.begin(), time.end(), time.begin());
    cout << (*max_element(time.begin(), time.end())) << endl;
    return 0;
}
