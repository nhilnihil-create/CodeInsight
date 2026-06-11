#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
ll D[MAXN];
vector <int> edge[MAXN];

map <ll, int> ord;
map <ll, int> ssize;
map <ll, ll> stot;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> D[i];
        ord[D[i]] = i;
        ssize[D[i]] = 1;
        stot[D[i]] = 0;
    }

    for (auto it = ord.rbegin(); it != ord.rend(); it++)
    {
        ll cv = it -> first;
        int ind = it -> second;

        int csize = ssize[cv];
        if (csize == N) break;
        ll ntot = D[ind] - ((N - csize) - csize);
        //cout << cv << " " << ntot << "\n";
        if (ord.find(ntot) == ord.end())
        {
            cout << "-1\n";
            return 0;
        }

        ssize[ntot] += csize;
        stot[ntot] += (stot[cv] + ssize[cv]);
        edge[ord[ntot]].push_back(ind);
    }
    //cout << "made it\n";

    int mloc = 0;
    for (int i = 0; i < N; i++)
        if (D[i] < D[mloc])
            mloc = i;
    if (stot[D[mloc]] != D[mloc])
    {
        cout << "-1\n";
        return 0;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int neigh : edge[i])
                cout << neigh + 1 << " " << i + 1 << "\n";
        }
    }
}