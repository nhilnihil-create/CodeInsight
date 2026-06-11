#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define ALL(a) a.begin(),a.end()
#define INIT(a,b) memset(a,b,sizeof(a))
using lint = long long int;

int main() {
    int M, K;
    cin >> M >> K;

    if (M == 0) {
        cout << (K == 0 ? "0 0" : "-1") << endl;
    }

    if (M == 1) {
        cout << (K == 0 ? "0 0 1 1" : "-1") << endl;
    }

    if (M >= 2) {
        if (K >= (1 << M)) {
            puts("-1");
            return 0;
        }
        
        vector<int> a;
        for_(i,0,1<<M) if (i != K) a.push_back(i);
        vector<int> b = a;
        reverse(ALL(b));

        int m = a.size();
        for (int x : a) cout << x << " ";
        cout << K << " ";
        for (int x : b) cout << x << " ";
        cout << K << endl;
    }
}