/**
 * Title:
 * Url:
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<numeric>
#include<functional>
#include<sstream>
#include<iomanip>

using namespace std;

#define ll long long

int main() {

    int N; cin >> N;
    vector<pair<int, int>> a(N), b(N);
    for(int i=0; i<N; i++) {
        int ax, ay; cin >> ax >> ay;
        a[i] = pair<int, int>(ax, ay);
    }
    for(int i=0; i<N; i++) {
        int bx, by; cin >> bx >> by;
        b[i] = pair<int, int>(by, bx);
    }
    int ans = 0;
    sort(a.begin(), a.end(), std::greater<pair<int, int>>());
    sort(b.begin(), b.end());
    for(int i=0; i<N; i++) {
        int bx = b[i].second;
        int by = b[i].first;
        for(int j=0; j<a.size(); j++) {
            if(by>=a[j].second&bx>=a[j].first) {
                ans++;
                a.erase(a.begin()+j);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}