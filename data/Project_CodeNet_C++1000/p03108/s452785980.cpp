#include<iostream>
#include<vector>

using namespace std;
typedef unsigned long long ll;

class DisjoitSet{
    public:
        vector<ll> rank, p,size;
        DisjoitSet(){}
        DisjoitSet(int n){
            rank.resize(n, 0);
            p.resize(n, 0);
            size.resize(n, 0);
            for (int i = 0; i < n; i++)
            {
                makeSet(i);
            }
        }
        void makeSet(int x){
        p[x] = x;
        rank[x] = 0;
        size[x] = 1;
        }

        bool same(int x, int y){
            return findSet(x) == findSet(y);
        }

        void unite(int x, int y){
            link(findSet(x), findSet(y));
        }

        void link(int x, int y){
            if (rank[x] > rank[y]){
                p[y] = x;
                size[x] += size[y];
            }
            else
            {
                p[x] = y;
                size[y] += size[x];
                if (rank[x] == rank[y])
                {
                    rank[y]++;
                }
            }
        }
        ll sized(int x)
        {
           int p = findSet(x);
           return size[p];
        }
        int findSet(int x){
            if (x != p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};

int main(){
    int n, m;
    cin >> n >> m;
    DisjoitSet ds = DisjoitSet(n + 1);
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    vector<ll> ans(m+1, 0);
    ans[m] = (ll)n * (n - 1) / 2;
    for (int i = m-1; i > -1 ; i--)
    {
        int a = v[i].first;
        int b = v[i].second;
        if(!ds.same(a,b))
        {
            ans[i] = ans[i + 1] - (ll)ds.sized(a) * (ll)ds.sized(b);
            ds.unite(a, b);
        }
        else
        {
            ans[i] = ans[i + 1];
        }
        
    }
    for (int i = 1; i < m+1; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}