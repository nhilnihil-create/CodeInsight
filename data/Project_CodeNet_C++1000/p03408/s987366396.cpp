#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N ;

    vector<string> blues(N);
    for (int i = 0; i < N; i++) cin >> blues.at(i);

    cin >> M ;
    vector<string> reds(M);
    for (int i = 0; i < M; i++) cin >> reds.at(i);

    sort(blues.begin(), blues.end());
    sort(reds.begin(),  reds.end());

    for (int i = 0; i < N; i++) {
        string blue = blues.at(i);
        for (int j = 0; j < M; j++) {
            string red = reds.at(j);
            if (blue == red) {
                blues.at(i) = "";
                reds.at(j)  = "";
                break;
            }
        }
    }

    int sum = 0, max_sum = 0;
    string prev = "";
    for (int i = 0; i < N; i++) {
        string curr = blues.at(i);
//        cout << "curr1: " << curr << endl;
        if (curr != "") {
            if (curr != prev) {
//                cout << "curr: " << curr << ", prev: " << prev << endl;
                sum = 1;
            } else {
                sum++;
//                cout << "sum: " << sum << endl;
            }

            if (sum > max_sum) {
                max_sum = sum;
            }

        }
        prev = curr;
    }

    cout << max_sum << endl;
}
