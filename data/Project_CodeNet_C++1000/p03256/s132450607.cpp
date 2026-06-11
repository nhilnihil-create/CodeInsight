#include <bits/stdc++.h>
using namespace std;

const int bm = 2 * (int)(1e5) + 5;
bool mode[bm];
int deg[bm][2];
int nbNoeuds, nbLiens;
vector<int> adj[bm];
bool vu[bm];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> nbNoeuds >> nbLiens;

    for (int iNod = 1; iNod <= nbNoeuds; ++iNod) {
        char lettre;
        cin >> lettre;
        mode[iNod] = (lettre == 'B');
    }
    for (int iLien = 0; iLien < nbLiens; ++iLien) {
        int nod1, nod2;
        cin >> nod1 >> nod2;
        adj[nod1].push_back(nod2);
        if (nod1 != nod2) adj[nod2].push_back(nod1);
        deg[nod1][mode[nod2]]++;
        if (nod1 != nod2) deg[nod2][mode[nod1]]++;
    }

    stack<int> pile;
    for (int iNod = 1; iNod <= nbNoeuds; ++iNod) {
        if (deg[iNod][0] == 0 || deg[iNod][1] == 0) {
            pile.push(iNod);
            vu[iNod] = true;
        }
    }
    int fini = 0;
    while (! pile.empty()) {
        int nod = pile.top();
        pile.pop();
        ++fini;
        for (int vo : adj[nod]) {
            if ((--deg[vo][mode[nod]]) == 0 && vu[vo] == false) {
                vu[vo] = true;
                pile.push(vo);
            }
        }
    }

    if (fini != nbNoeuds) cout << "Yes\n";
    else cout << "No\n";
}