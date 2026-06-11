    #include <iostream>
    using namespace std;
     
    int main() {
        int L; cin >> L;
        int tmp = (1<<20), N = 20;
        while(tmp > L) tmp >>= 1, --N;
     
        cout << N + 1 << " " << N * 2 + __builtin_popcount(L) - 1 << endl;
     
        // when L = 8
        // 1 - 2 - 3 - 4
        // cost : 01 02 04
        // path 1 ~ 4 : 000 100 020 120 004 104 024 124 (length : 0 ~ 7)
        for(int i = 0; i < N; ++i) {
            cout << i + 1 << " " << i + 2 << " " << 0 << '\n';
            cout << i + 1 << " " << i + 2 << " " << (1<<i) << '\n';
        }
        // for now, it can make the graph when L = 2^k
     
        // think about when L is between 2^k and 2^(k+1)
        // L = ... 4 : ok, 5 : more 1 path costs 4, 6 : more 2 path cost 4 and 5, 7 : more 3 path cost 4 and 5 and 6, 8 : ok
        // 5 : 101, 6 : 110, 7 : 111
     
     
        int cost = (1<<N);
        for(int i = N - 1; i >= 0; --i) {
            if(L & (1<<i)) {
                cout << i + 1 << " " << N + 1 << " " << cost << '\n';
                cost += (1<<i);
            }
        }
        return 0;
    }