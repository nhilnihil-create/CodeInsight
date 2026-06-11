#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef long long ll;

const double PI = 3.1415926535897932384626;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;
const double EPS = 1e-10;

class UnionFind{
public:

    vector<int> root;
    vector<int> rank;
    vector<int> sizev;

    UnionFind();

    //1-indexでアクセスすること想定
    UnionFind(int n){

        for(int i = 0; i <= n; i++){
            root.push_back(i);
            rank.push_back(1);
            sizev.push_back(1);
        }
    }

    int find(int n){

        vector<int> update;
        int count = 0;

        while(n != root[n]){
            
            update.push_back(n);
            n = root[n];
            count++;
        }

        for(int i = 0; i < count; i++){
            root[update[i]] = n;
        }

        return n;
    }

    int size(int n){
        return sizev[find(n)];
    }

    void merge(int a, int b){

        a = find(a);
        b = find(b);

        if(a != b){

            if(rank[a] < rank[b]){
                root[a] = b;
                sizev[b] += sizev[a];
            }else{
                root[b] = a;
                sizev[a] += sizev[b];

                if(rank[a] == rank[b]){
                    rank[a]++;
                }
            }
        
        }
    }
};

int main(){

    ll n;
    int m;
    cin >> n >> m;

    vector<ll> inconv;

    inconv.push_back(n * (n - 1) / 2);

    UnionFind uf(n);

    vector<pair<int,int>> v;

    rep(i, m){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    rep(i, m){
        int a, b;
        a = v[m - 1 - i].first;
        b = v[m - 1 - i].second;

        ll sizea = uf.size(a);
        ll sizeb = uf.size(b);

        //cerr << sizea << " " << sizeb << endl;

        if(uf.find(a) != uf.find(b)){
            inconv.push_back(inconv[i] - sizea * sizeb);
            uf.merge(a, b);
        }else{
            inconv.push_back(inconv[i]);
        }
    }

    reverse(ALL(inconv));

    rep(i, m){
        cout << inconv[i + 1] << endl; 
    }
    return 0;
}
