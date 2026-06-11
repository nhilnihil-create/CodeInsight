#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> P;

bool comp(P a, P b) {
    if (a.second > b.second)
        return true;
    else if (a.second == b.second && a.first > b.first)
        return true;
    else
    {
            return false;
    }
    
} 

int main() {
    int n;  cin >> n;
    P *ab = new P[n];
    for (int i = 0; i < n; i++)
        cin >> ab[i].first >> ab[i].second;
    
    P *cd = new P[n];
    for (int i = 0; i < n; i++)
        cin >> cd[i].first >> cd[i].second;

    sort(ab, ab+n, comp);
    sort(cd, cd+n);

    int ans = 0;
    vector<bool> check(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ab[j].first < cd[i].first && ab[j].second < cd[i].second && !check[j]) {
                check[j] = true;
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;    
}