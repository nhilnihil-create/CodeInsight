#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// #define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'

const int MOD = (int)1e9 + 7;

int calc_height(int Cx, int Cy, int H, int X, int Y) {
    int ans = H - abs(X - Cx) - abs(Y - Cy);

    return ans > 0 ? ans : 0;
}

int guess_height(int Cx, int Cy, int X, int Y, int low_h) {
    return low_h + abs(X - Cx) + abs(Y - Cy);
}


int main() {
    int N;
    cin >> N;

    vector<int> Xs(N);
    vector<int> Ys(N);
    vector<int> Hs(N);
    REP(i, N) {
        cin >> Xs.at(i) >> Ys.at(i) >> Hs.at(i);
    }

    int selected_i;
    int selected_h;
    REP(i, N) {
        int h = Hs.at(i);
        if (h > 0) {
            selected_i = i;
            selected_h = h;
        }
    }

    int selected_x = Xs[selected_i];
    int selected_y = Ys[selected_i];

    debug(selected_x);
    debug(selected_y);
    debug(selected_h);

    int cx, cy;
    FORE(cx, 0, 100) {
        FORE(cy, 0, 100) {
            int guessed_h = guess_height(cx, cy, selected_x, selected_y, selected_h);

            bool ok = true;
            REP(i, N) {
                int x = Xs[i];
                int y = Ys[i];
                int h = Hs[i];
                int calced_h = calc_height(cx, cy, guessed_h, x, y);

                if (calced_h != h) {
                  ok = false;
                    break;
                }
            }

            if (ok) {
                cout << cx << " " << cy << " " << guessed_h << endl;
                return 0;
            }




        }
    }


}
