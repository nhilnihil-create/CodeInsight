#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int64_t r[100'000];
int64_t l[100'000];

int main()
{
    int n;
    cin >> n;
    priority_queue<int64_t, vector<int64_t>, greater<int64_t>> rq1, rq2;
    priority_queue<int64_t, vector<int64_t>, less<int64_t>> lq1, lq2;

    rep(i, n)
    {
        cin >> l[i] >> r[i];

        rq1.push(r[i]);
        lq1.push(l[i]);
    }
    rq2 = rq1;
    lq2 = lq1;

    int64_t score1 = 0;
    int64_t cr = 0, cl = 0;
    while (true) {
        if (lq1.empty() || lq1.top() < cr) {
            score1 += abs(cr);
            break;
        }
        cl = lq1.top();
        lq1.pop();
        score1 += cl - cr;

        if (rq1.empty() || rq1.top() > cl) {
            score1 += abs(cl);
            break;
        }
        cr = rq1.top();
        rq1.pop();
        score1 += cl - cr;
    }

    int64_t score2 = 0;
    cl = cr = 0;
    while (true) {
        if (rq2.empty() || rq2.top() > cl) {
            score2 += abs(cl);
            break;
        }
        cr = rq2.top();
        rq2.pop();
        score2 += cl - cr;

        if (lq2.empty() || lq2.top() < cr) {
            score2 += abs(cr);
            break;
        }
        cl = lq2.top();
        lq2.pop();
        score2 += cl - cr;
    }
    cout << max(score1, score2) << endl;
    return 0;
}