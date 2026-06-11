#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define NMAX 200001

vector <int> v[NMAX];
char labels[NMAX];
int nra[NMAX], nrb[NMAX], viz[NMAX];

int main()
{
    ios::sync_with_stdio(false);

    int n, m;
    // ifstream cin("code.in");
    cin >> n >> m;
    cin >> (labels + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        if (x != y) {
            v[y].push_back(x);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (const int x : v[i]) {
            if (labels[x] == 'A')
                nra[i]++;
            else
                nrb[i]++;
        }
    }

    queue <int> q;
    for (int i = 1; i <= n; i++) {
        if (nra[i] == 0 || nrb[i] == 0) {
            q.push(i);
            viz[i] = 1;
        }
    }

    while (!q.empty()) {
        int nod = q.front();
        q.pop();
        for (const int x : v[nod]) {
            if (viz[x])
                continue;
            if (labels[nod] == 'A')
                nra[x]--;
            else
                nrb[x]--;
            if (nra[x] == 0 || nrb[x] == 0) {
                q.push(x);
                viz[x] = 1;
            }
        }
    }

    int found = 0;
    for (int i = 1; i <= n; i++) {
        if (viz[i] == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << '\n';

    return 0;
}
