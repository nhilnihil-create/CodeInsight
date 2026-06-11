// https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Codejam_template.cpp
#pragma GCC optimize("Ofast") // OPTIONAL: for faster execution
#include <bits/stdc++.h>      // import everything in one shot
using namespace std;
// defines
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define invrep(i, a, b) for (int i = b - 1; i >= a; --i)
#define umap unordered_map
#define uset unordered_set
// typedefs
typedef unsigned int uint;
typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
// -------------------------------

typedef struct {
    int points;
    int cost;
    int idx;
}
triple;

int main()
{
    // OPTIONAL: for faster input/output (only if using cin/cout)
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    vi A(N);
    rep(i, 0, N) cin >> A[i];
    vector<triple> left;
    set<int> negatives;
    int pointsSum = 0;
    rep(i, 0, N)
    {
        pointsSum += A[i];
        if (A[i] < 0)
            negatives.insert(A[i]);
        else
        {
            left.emplace_back(triple{pointsSum, i + 1, i});
            int j = 1;
            int negSum = 0;
            for (auto it = negatives.begin(); it != negatives.end(); it++)
            {
                negSum += *it;
                left.emplace_back(triple{pointsSum-negSum, i + 1 + j, i});
                j++;
            }
        }
    }

    vector<triple> right;
    negatives.clear();
    pointsSum = 0;
    invrep(i, 0, N)
    {
        pointsSum += A[i];
        if (A[i] < 0)
            negatives.insert(A[i]);
        else
        {
            right.emplace_back(triple{pointsSum, N - i, i});
            int j = 1;
            int negSum = 0;
            for (auto it = negatives.begin(); it != negatives.end(); it++)
            {
                negSum += *it;
                right.emplace_back(triple{pointsSum - negSum, N - i + j, i});
                j++;
            }
        }
    }
    int ans = 0;
    rep(pos, 0, N)
    {
        rep(moves, 1, K+1) {
            int l = 0, r = 0;
            rep(i, 0, left.size()) {
                if (left[i].idx > pos) break;
                if (left[i].cost <= moves) l = max(l, left[i].points);
            }
            rep(i, 0, right.size()) {
                if (right[i].idx <= pos) break;
                if (right[i].cost <= K - moves)r = max(r, right[i].points);
            }
            ans = max(ans, l + r);
        }
    }
    cout << ans << endl;
    // rep(i, 0, left.size())
    // {
    //     printf("%d %d %d\n", left[i].points, left[i].cost, left[i].idx);
    // }
    // printf("\n");
    // rep(i, 0, right.size())
    // {
    //     printf("%d %d %d\n", right[i].points, right[i].cost, right[i].idx);
    // }
    return 0;
}