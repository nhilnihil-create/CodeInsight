#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define va first
#define vb second
using namespace std;
using pii = pair<int,int>;

int n, k, q;
int a[2005];
set<pii> S;

vector<int> cmp;

void input(){
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cmp.push_back(a[i]);
    }
    sort(all(cmp));
    cmp.resize(unique(all(cmp)) - cmp.begin());
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    input();
    S.emplace(1, n);
    vector<int> tmp, ump;
    vector<pii> vmp, wmp;
    tmp.reserve(n);
    ump.reserve(n);
    vmp.reserve(n);
    wmp.reserve(n);
    int ans = INT_MAX;
    for(int i = 0; i < cmp.size(); i++){
        tmp.clear();
        for(pii p : S){
            ump.clear();
            for(int u = p.va; u <= p.vb; u++){
                ump.push_back(a[u]);
            }
            sort(all(ump));
            for(int i = 0; i < p.vb - p.va - k + 2; i++) tmp.push_back(ump[i]);
        }
        sort(all(tmp));
        if(tmp.size() < q) break;
        ans = min(ans, tmp[q-1] - tmp[0]);
        vmp.clear();
        wmp.clear();
        for(pii p : S){
            int cur = p.va - 1;
            int flag = 0;
            for(int u = p.va; u <= p.vb; u++){
                if(a[u] == cmp[i]){
                    if(!flag){
                        wmp.push_back(p);
                        flag = 1;
                    }
                    vmp.emplace_back(cur + 1, u - 1);
                    cur = u;
                }
            }
            vmp.emplace_back(cur + 1, p.vb);
        }
        for(pii p : wmp) S.erase(p);
        for(pii p : vmp){
            if(p.vb - p.va + 1 >= k) S.insert(p);
        }
    }
    cout << ans << '\n';
}
