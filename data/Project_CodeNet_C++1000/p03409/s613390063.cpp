#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N; cin >> N;
    vector<vector<int>> points(2 * N, vector<int>(2 * N, 0));
    vector<pair<int, int>> blue(N);
    rep(i, N){
        int a, b;
        cin >> a >> b;
        points[a][b] = 1;
    }
    rep(i, N){
        int a, b;
        cin >> a >> b;
        blue[i] = make_pair(a, b);
    }

    int ans = 0;
    sort(all(blue));
    rep(k, N){
        int x = blue[k].first, y = blue[k].second;
        bool flag = false;
        for(int j = y; j >= 0; j--){
            for(int i = x; i >=0; i--){
                if(points[i][j] == 1){
                    ans++;
                    points[i][j] = 0;
                    flag = true;
                    break;
                }
            }
            if(flag == true) break;
        }
    }
    cout << ans << endl;
}