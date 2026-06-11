#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n;
    cin >> n;

    int sum = 0;
    int x = 0;
    while(sum < n){
        sum += ++x;
    }

    if(sum != n){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    if(n == 1){
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    vector<vector<int>> ans(x+1, vector<int>());
    ans[0].push_back(1);
    ans[0].push_back(2);
    ans[1].push_back(2);
    ans[1].push_back(3);
    ans[2].push_back(3);
    ans[2].push_back(1);

    if(n == 3){
        cout << x+1 << endl;
        rep(i, x+1){
            int m = ans[i].size();
            cout << m << " ";
            rep(j, m-1){
                cout << ans[i][j] << " ";
            }
            cout << ans[i][m-1] << endl;
        }
        return 0;
    }

    int y = 4;
    for(int s = 3; s <= x; s++){
        for(int t = 0; t < s; t++){
            ans[s].push_back(y);
            ans[t].push_back(y);
            y++;
        }
    }

    cout << x+1 << endl;
    rep(i, x+1){
        int m = ans[i].size();
        cout << m << " ";
        rep(j, m-1){
            cout << ans[i][j] << " ";
        }
        cout << ans[i][m-1] << endl;
    }

    return 0;
}
