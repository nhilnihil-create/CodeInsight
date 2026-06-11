#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;

void dump(vector<int> v) {
    rep(i, v.size()) cout << v[i] << " ";
    cout << endl;
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> l(n);
    rep(i, n) cin >> l[i];
    
    int n_pat = 1;
    rep(i, n) n_pat *= 4;

    int best = 1e8;
    rep(pat, n_pat) {
        vector<int> A, B, C;

        int t_pat = pat;
        rep(i, n) {
            if (t_pat % 4 == 1) {
                A.push_back(i);
            }
            else if (t_pat % 4 == 2) {
                B.push_back(i);
            }
            else if (t_pat % 4 == 3) {
                C.push_back(i);
            }
            t_pat /= 4;
        }

        int lA = 0;
        rep(i, A.size()) lA += l[A[i]];
        int lB = 0;
        rep(i, B.size()) lB += l[B[i]];
        int lC = 0;
        rep(i, C.size()) lC += l[C[i]];

        if (A.size() <= 0 || B.size() <= 0 || C.size() <= 0) {
            continue;
        }

        int mp = 10 * (A.size() + B.size() + C.size() - 3);
        mp += abs(a - lA);
        mp += abs(b - lB);
        mp += abs(c - lC);

        // if (best > mp) {
        //     put(mp);
        //     cout << lA << "/" << lB << "/" << lC << endl;
        //     dump(A);
        //     dump(B);
        //     dump(C);
        // }
        best = min(best, mp);
    }

    put(best)
    return 0;
}