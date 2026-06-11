#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

bool xcmp(pair<long long int, long long int> a, pair<long long int, long long int> b) {
    if(a.first!=b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

bool ycmp(pair<long long int, long long int> a, pair<long long int, long long int> b) {
    if(a.second!=b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    int K, N;
    cin >> N >> K;
    vector<pair<long long int, long long int> > xy(N);
    for(int n=0; n<N; n++) {
        cin >> xy[n].first >> xy[n].second;
    }
    
    sort(xy.begin(), xy.end(), xcmp);

    long long int ans=1e9;
    ans *= ans;
    ans *= 5;
    for(int i=0; i<N; i++) {
        for(int j=i+K-1; j<N; j++) {
            vector<long long int> y;
            long long int tmpx = abs(xy[j].first-xy[i].first);
            for(int k=i; k<=j; k++) {
                y.push_back(xy[k].second);
            }
            sort(y.begin(), y.end());
            long long int tmpy;
            for(int k=0; k+K-1<y.size(); k++) {
                tmpy = abs(y[k]-y[k+K-1]);
                if(ans > tmpx*tmpy) {
                    ans = tmpx*tmpy;
                }
            }
        }
    }
    
    cout << ans << endl;

    return 0;
    
}