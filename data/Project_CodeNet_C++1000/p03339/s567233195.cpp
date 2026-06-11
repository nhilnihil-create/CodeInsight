#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int min_count = N;

/*    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            //cout << "i = " << i << " j = " << j << endl;
            if ( j < i && S[j] == 'W') {
                //cout << "j < i count++;" << endl;
                count++;
            } else if ( i < j && S[j] == 'E') {
                //cout << "i < j count++;" << endl;
                count++;
            }
            if (count > min_count) {
                break;
            }
        }
        min_count = min(min_count, count);
    }*/
    vector<pair<int, int>> E_W(N);
    int Enum = 0, Wnum = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'E') {
            Enum++;
        } else if (S[i] == 'W') {
            Wnum++;
        }
        E_W[i] = make_pair(Enum, Wnum);
    }

    for (int i = 0; i < N; i++) {
        int toE, toW;
        if (i == 0) {
            toE = 0;
            toW = E_W[N - 1].first - E_W[0].first;
        } else {
            toE = E_W[i - 1].second;
            toW = E_W[N - 1].first - E_W[i].first;
        }
        //cout << "i = " << i << ", toE = "<< toE << ", toW = " << toW << endl;
        min_count = min(min_count, toE + toW);
    }
    cout << min_count << endl;

    return 0;
}