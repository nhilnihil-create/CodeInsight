#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int N; vector<pair<int,int>> red,blue;
void input()
{
    cin >> N;
    red.resize(N);
    for (int i = 0; i < N; ++i) cin >> red[i].first >> red[i].second;
    blue.resize(N);
    for (int i = 0; i < N; ++i) cin >> blue[i].first >> blue[i].second;
}

void solve()
{
    sort(red.begin(),red.end());
    sort(blue.begin(),blue.end());   
    vector<int> is_checked(N,0);

    int ans = 0;
    for (int i = 0; i < N; ++i){
        int max_y_value = -1, max_y_num = -1;
        for (int j = 0; j < N; ++j){
            if (red[j].first >= blue[i].first) break;
            if (red[j].second >= blue[i].second || is_checked[j] == 1) continue;
            if (max_y_value <= red[j].second){
                max_y_value = red[j].second;
                max_y_num = j;
            }
        }
        if (max_y_num == -1) continue;
        is_checked[max_y_num] = 1;
        ++ans;
    }
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}