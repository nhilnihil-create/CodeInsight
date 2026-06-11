#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int N;
ll D[100005];
ll parent[100005];
map<ll,int> tree_sizes;

map<ll,int> D_to_old;
int new_to_old[100005];

int main() {
        cin >> N;
        for (int i=0; i<N; i++) {
                cin >> D[i];
                tree_sizes[D[i]] = 1;
                D_to_old[D[i]] = i;
                parent[i] = -1;
        }

        sort(D,D+N);

        for (int i=0; i<N; i++) {
                new_to_old[i] = D_to_old[D[i]];
        }

        ll tot_depth = 0;
        for (int i=N-1; i>=1; i--) {
                if (N - 2*tree_sizes[D[i]] <= 0) {
                        cout << "-1\n";
                        return 0;
                }

                auto new_parent = tree_sizes.find(D[i] - (N - 2*tree_sizes[D[i]]));
                if (new_parent == tree_sizes.end()) {
                        cout << "-1\n";
                        return 0;
                }

                parent[new_to_old[i]] = D_to_old[new_parent->first];
                new_parent->second += tree_sizes[D[i]];
                tot_depth += tree_sizes[D[i]];
        }

        if (D[0] != tot_depth) {
                cout << "-1\n";
                return 0;
        }

        for (int i=0; i<N; i++) {
                if (parent[i] != -1) {
                        cout << i+1 << " " << parent[i]+1 << endl;
                }
        }
}