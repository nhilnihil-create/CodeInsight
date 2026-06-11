#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector< pair<int,int> > A(N+2);
    for(int i=1; i<=N; i++) {
        cin >> A[i].first;
    }
    for(int i=0; i<N+2; i++) {
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    int ans = numeric_limits<int>::max();
    for(int i=2; i<N+2; i++) {
        int q = Q;
        vector<int> tmp;
        int Y = A[i].first;
        for(int j=0; j<N+2; j++) {
            if(A[j].first < Y) {
                tmp.emplace_back(A[j].second);
            }
        }
        sort(tmp.begin(), tmp.end());
        vector<int> diff(tmp.size());
        for(int j=1; j<diff.size(); j++) {
            diff[j] = tmp[j] - tmp[j-1] - 1;
        }
        for(int j=tmp.size(); j<N+2; j++) {
            auto itr = upper_bound(tmp.begin(), tmp.end(), A[j].second);
            int dist = distance(tmp.begin(), itr);
            if(diff[dist] >= K) {
                --diff[dist];
                --q;
            }
            if(q == 0) {
                int X = A[j].first;
                ans = min(ans, X-Y);
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
