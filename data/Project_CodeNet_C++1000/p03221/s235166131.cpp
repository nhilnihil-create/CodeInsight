#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct city {
    int id;
    int prefecture;
    int birth;
    string number;
};

bool id_cmp(const struct city& l, const struct city& r) { return l.id < r.id; }
bool birth_cmp(const struct city& l, const struct city& r) {
    return l.birth < r.birth;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<city> cities(M);
    for (int i = 0; i < M; i++) {
        int prefecture, birth;
        cin >> prefecture >> birth;
        cities[i].id = i;
        cities[i].prefecture = prefecture;
        cities[i].birth = birth;
    }
    sort(cities.begin(), cities.end(), birth_cmp);
    vector<int> p(N, 0);

    for (int i = 0; i < M; i++) {
        int pr = cities[i].prefecture;
        int q = p[pr - 1] + 1;
        p[pr - 1]++;
        std::ostringstream sout;
        sout << setfill('0') << setw(6) << pr;
        sout << setfill('0') << setw(6) << q;
        cities[i].number = sout.str();
    }

    sort(cities.begin(), cities.end(), id_cmp);

    for (int i = 0; i < M; i++) {
        cout << cities[i].number << endl;
    }

    return 0;
}
