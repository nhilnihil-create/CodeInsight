#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

/**
 * UnionFind(重みなし)
 */
class UnionFind
{
    private:
        vector<long long> parents;

    public:
        UnionFind(long long N)
        {
            this->parents = vector<long long>(N, -1);
        }

        long long size(long long A)
        {
            return -1 * this->root(A);
        }

        long long root(long long A)
        {
            if (this->parents[A] < 0) return A;

            this->parents[A] = this->root(this->parents[A]);
            return this->parents[A];
        }

        bool unite(long long A, long long B)
        {
            long long ra = this->root(A);
            long long rb = this->root(B);

            if (ra == rb) return false;

            if (this->size(ra) > this->size(rb)) {
                this->parents[ra] += this->parents[rb];
                this->parents[rb] = ra;
            } else {
                this->parents[rb] += this->parents[ra];
                this->parents[ra] = rb;
            }
            return true;
        }

        bool isUnite(long long A, long long B)
        {
            return this->root(A) == this->root(B);
        }

        void show()
        {
            for (int i = 0; i < this->parents.size(); i++) {
                this->root(i); // 親の更新を行う
                cout << "i: " << i << ", parents[i]: " << this->parents[i] << endl;
            }
        }
};


int main() {
    int N, M;
    cin >> N >> M;

    vi P(N);
    rep(i, N) {
        cin >> P[i];
        P[i]--;
    }
    vi X(M), Y(M);
    rep(i, M) {
        cin >> X[i] >> Y[i];
        X[i]--;
        Y[i]--;
    }

    UnionFind u(N);
    rep(i, M) {
        u.unite(P[X[i]], P[Y[i]]);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (u.isUnite(i, P[i])) cnt++;
    }
    cout << cnt << endl;
}