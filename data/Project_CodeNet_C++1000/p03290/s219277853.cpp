#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int ctoi(char c){
    return (int)(c - '0');
}

int main() {
    int D;
    ll G;
    cin >> D >> G;

    vector<vector<int>> data(D, vector<int>(2));
    ll point;
    int solved, ans;
    bool isOK;

    rep(i, D){
        int p, c;
        cin >> p >> c;
        data[i] = {p, c};
    }

    ans = INF;
    for(int i = (1 << D) - 1; i >= 0; i--){
        solved = 0;
        point = 0;
        isOK = false;
        bitset<10> bit(i);
        rep(j, D){
            if(bit.test(j)){
                point += ((D - j) * 100 * data[D - 1 - j][0] + data[D - 1 - j][1]);
                solved += data[D - 1 - j][0];
            }
        }

        rep(j, D){
            if(point >= G){
                isOK = true;
                break;
            }
            if(!bit.test(j)){
                int forpt;
                forpt = (G - point) / (D - j) / 100;
                if(forpt > data[D - 1 - j][0] - 1){
                    break;
                } else {
                    isOK = true;
                    solved += forpt;
                }
            }
        }

        if(isOK){
            ans = min(ans, solved);
        } 

    }
    cout << ans << endl;

    return 0;
}
