#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> D(N,0);
    map<int, int> d;
    map<int, int> t;
    for(int i = 0; i < N; i++) {
        cin >> D.at(i);
        if(!d.count(D.at(i))) {
            d[D.at(i)] = 0;
        }
        d.at(D.at(i))++;
    }
    int M = 0;
    cin >> M;
    vector<int> T(M,0);
    for(int i = 0; i < M; i++) {
        cin >> T.at(i);
        /*
        if(!t.count(T.at(i))) {
            d[T.at(i)] = 0;
        }
        t.at(T.at(i))++;
        */
    }

    for(int i = 0; i < M; i++) {
        if(!d.count(T.at(i))) {
            cout << "NO" << endl;
            return 0;
        }
        if(d.at(T.at(i)) == 0) {
            cout << "NO" << endl;
            return 0;
        }
        d.at(T.at(i))--;
    }
    cout << "YES" << endl;



    return 0;
}