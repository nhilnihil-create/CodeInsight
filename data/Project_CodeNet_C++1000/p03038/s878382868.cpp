#include<string>
#include<iostream>
#include<deque>
#include<cstdlib>
#include<algorithm>
using namespace std;
using ulli = long long int;

int main() {
    int n, m;
    cin >> n >> m;
    deque<ulli> cards;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cards.push_back(temp);
    }
    sort(cards.begin(), cards.end());
    deque<pair<int, ulli>> bc;
    for (int i = 0; i < m; i++) {
        int b;
        ulli c;
        cin >> b >> c;
        bc.emplace_back(make_pair(b, c));
    }
    sort(bc.begin(), bc.end(), [](auto const& lhs, auto const& rhs) { return lhs.second > rhs.second; });
    ulli res = 0;
    deque<ulli>::iterator p=cards.begin();

    while (!bc.empty() && bc.front().second > *p && p!=cards.end()) {
        *p = bc.front().second;
        bc.front().first--;
        p++;
        if (bc.front().first == 0) {
            bc.pop_front();
        }
    }
    while (!cards.empty()) {
        res += cards.front();
        cards.pop_front();
    }
    cout << res << endl;
    return 0;
}