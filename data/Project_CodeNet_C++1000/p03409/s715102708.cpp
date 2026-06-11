#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int,int>> red(n);
    vector<pair<int,int>> blue(n);

    for(int i = 0; i < n; i++) cin >> red[i].second >> red[i].first;
    for(int i = 0; i < n; i++) cin >> blue[i].first >> blue[i].second;

    sort(red.rbegin(),red.rend());
    sort(blue.begin(),blue.end());

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(blue[i].first > red[j].second && blue[i].second > red[j].first){
                ans++;
                red[j].first = 2 * n;
                red[j].second = 2 * n;
                blue[i].first = 0;
                blue[i].second = 0;
            }
        }
    }
    cout << ans << endl;
}
