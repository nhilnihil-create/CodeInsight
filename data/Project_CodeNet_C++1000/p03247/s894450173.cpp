#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    bool flag = false;
    int eo = 0;
    for(int i=0; i<N; ++i) {
        cin >> X[i] >> Y[i];
        if(i == 0) eo = abs((X[0] + Y[0] + 2) % 2);
        else if(eo != abs((X[i] + Y[i]) % 2)) flag = true;
    }
    if(flag) {
        cout << -1 << endl;
        return 0;
    }

    if(eo == 1) {
        cout << 31 << endl;
        for(int i=0; i<31; ++i) cout << (1LL << i) << (i!=30 ? ' ' : '\n');
        for(int i=0; i<N; ++i) {
            long long tmp1 = (X[i] + Y[i] + (1LL<<31) - 1) / 2;
            long long tmp2 = (X[i] - Y[i] + (1LL<<31) - 1) / 2;
            for(int d=0; d<31; ++d) {
                int fx = (tmp1 >> d) & 1;
                int fy = (tmp2 >> d) & 1;
                if(fx && fy) cout << 'R';
                else if(fx) cout << 'U';
                else if(fy) cout << 'D';
                else cout << 'L';
            }
            cout << endl;
        }
    } else {
        cout << 32 << endl << "1 ";
        for(int i=0; i<31; ++i) cout << (1LL << i) << (i!=30 ? ' ' : '\n');
        for(int i=0; i<N; ++i) {
            cout << 'L';
            long long tmp1 = (X[i] + 1 + Y[i] + (1LL<<31)) / 2;
            long long tmp2 = (X[i] + 1 - Y[i] + (1LL<<31)) / 2;
            for(int d=0; d<31; ++d) {
                int fx = (tmp1 >> d) & 1;
                int fy = (tmp2 >> d) & 1;
                if(fx && fy) cout << 'R';
                else if(fx) cout << 'U';
                else if(fy) cout << 'D';
                else cout << 'L';
            }
            cout << endl;
        }
    }    
}