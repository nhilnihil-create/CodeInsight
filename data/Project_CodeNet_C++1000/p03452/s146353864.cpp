#include <iostream>
#include <vector>
using namespace std;

struct ver {
    int l, r, d;
};
vector <ver> v;
vector <pair <int, int> > tr[100010];

int viz[100010], t[100010], n, m, l, r, d, ver;

void dfs(int nod) {
    if (ver == 1) {
        return;
    }
    //cout << "NODUL: " << nod <<'\n';
    for (int i = 0; i < tr[nod].size(); i++) {
        int r = tr[nod][i].first;
        //cout << "ACESTA ESTE R : --> " << r << '\n';
        if (viz[r] == 0) {
            viz[r] = viz[nod] + tr[nod][i].second;

        dfs(r);
        } else if (viz[r] != viz[nod] + tr[nod][i].second) {
            ver = 1;
            return;
        }
    }
}

int main()
{
    cin >> n >> m;
    tr[0].push_back({0, 0});
    for (int i = 1; i <= m; i++) {
        struct ver man;
        cin >> man.l >> man.r  >> man.d;
        t[man.r] = man.l;
        tr[man.l].push_back({man.r, man.d});
    }
    ver = 0;
    for (int i = 1; i <= n; i++){
        if (viz[i] == 0) {
            int x = i;
            int nr = 0;
            while (t[x] !=0) {
                x = t[x];
                nr++;
                if (nr > n) {
                    cout << "No\n";
                    return 0;
                }
            }
            viz[x] = 1;
            //cout << "AHA\n";
            dfs(x);
            if (ver == 1) {
                cout << "No\n";
                return 0;
            }
        }
    }
    /*
    for (int i = 0; i < v.size(); i++) {
        if (viz[v[i].r] != viz[v[i].l] + v[i].d && (viz[v[i].r] != 0 && viz[v[i].l] != 0)) {
            cout << "No";
            return 0;
        }
    }
    */
    cout << "Yes";
    return 0;
}
