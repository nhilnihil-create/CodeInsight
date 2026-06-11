#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
        int N;
        cin >> N;
        int D[N];
        rep(i,N) cin >> D[i];
        int M;
        cin >> M;
        int T[M];
        rep(i,M) cin >> T[i];

        sort(D,D+N);
        sort(T,T+M);

        int k = 0;
        rep(i,M){
                while (D[k] < T[i]) {
                        if (k >= N) {
                                cout << "NO" << endl;
                                return 0;
                        }
                        k++;
                }

                if (D[k] == T[i]) k++;
                else if (D[k] > T[i]) {
                                cout << "NO" << endl;
                                return 0;
                }
        }

        cout << "YES" << endl;

        return 0;
}