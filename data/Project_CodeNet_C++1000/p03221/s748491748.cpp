#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int num;
    int pref;
    int year;
    int rank;
} City;

int main() {
    int n, m;
    int p[100000], y[100000];
    City city[100000];
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> p[i] >> y[i];
        city[i] = {i, p[i], y[i], 0};
    }

    sort(city, city + m, [](City a, City b) -> bool {
        if (a.pref < b.pref) return true;
        if (a.pref == b.pref && a.year < b.year) return true;
        return false;
    });

    int r = 1;
    for (int i = 0; i < m - 1; i++) {
        city[i].rank = r;
        r++;
        if (city[i + 1].pref != city[i].pref) r = 1;
    }
    city[m - 1].rank = r;

    sort(city, city + m, [](City a, City b) -> bool {
        return a.num < b.num;
    });

    for (int i = 0; i < m; i++) {
        string pStr = to_string(city[i].pref);
        while (pStr.length() != 6) pStr.insert(0, "0");
        string rStr = to_string(city[i].rank);
        while (rStr.length() != 6) rStr.insert(0, "0");
        cout << pStr << rStr << endl;
    }
}