#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    using psii = tuple<string, int, int>;

    vector<psii> Data(N);

    string fir;
    int sec;
    for(int i = 0; i < N; i++) {
        cin >> fir >> sec;
        Data.at(i) = make_tuple(fir, -1*sec, i+1);
    }

    sort(Data.begin(), Data.end());

    for(int i = 0; i < N; i++) {
        cout << get<2>(Data.at(i)) << endl;
    }
}
