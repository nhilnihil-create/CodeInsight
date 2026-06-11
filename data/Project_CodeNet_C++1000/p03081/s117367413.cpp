#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2 * 100 * 1000 + 10;

int n, q, ans;
string st;
pair <char, int> Spell[N];

void input() {
    cin >> n >> q;
    cin >> st;

    char tmp;
    for (int i = 0; i < q; i++) {
        cin >> Spell[i].first >> tmp;
        if (tmp == 'R')
            Spell[i].second++;
        else
            Spell[i].second--;
    }
    return;
}

bool f(int x) {
    int pnt = 0;
    while (pnt < q && 0 <= x) {
        if (st[x] == Spell[pnt].first)
            x += Spell[pnt].second;
        if (x >= n)
            return false;
        pnt++;
    }

    if (x < 0)
        return true;
    return false;
}

int BinSearch(int l, int r) {
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (f(mid))
            l = mid;
        else
            r = mid;
    }
    return r;
}

int main() {
    input() ;
    ans += BinSearch(-1, n) ;

    reverse(st.begin(), st.end()) ;
    for (int i = 0; i < q; i++)
        Spell[i].second *= -1;

    ans += BinSearch(-1, n) ;

    cout << n - ans << endl;
    return 0;
}
