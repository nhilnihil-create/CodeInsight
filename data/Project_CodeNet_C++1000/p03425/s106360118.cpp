#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define aint(v) v.begin(),v.end()
#define endl "\n"
#define all(v) v.begin(),v.end()
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<15> MASK;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int MAX = 2e3 + 5;

struct DSU {
    int parent[MAX];
    int groupSize[MAX];
    int rank[MAX];
    int CC;

    DSU() {
        CC = MAX;
        for (int i = 0; i < MAX; ++i) {
            parent[i] = i;
            groupSize[i] = 1;
        }
    }

    int findLeader(int node) {
        if (parent[node] == node)return node;
        return parent[node] = findLeader(parent[node]);
    }

    int sameGroup(int i, int j) {
        return findLeader(i) == findLeader(j);
    }

    int mergeGroup(int i, int j) {
        int leader1 = findLeader(i);
        int leader2 = findLeader(j);
        if (leader1 == leader2)return 0;
        CC--;
        if (groupSize[leader1] > groupSize[leader2]) {
            parent[leader2] = leader1;
            groupSize[leader1] += groupSize[leader2];
        } else {
            parent[leader1] = leader2;
            groupSize[leader2] += groupSize[leader1];

        }
        return 1;
    }

    void mergeGroupByRank(int i, int j) {
        int leader1 = findLeader(i);
        int leader2 = findLeader(j);
        if (leader1 == leader2)return;
        if (rank[leader1] < rank[leader2])swap(leader1, leader2);
        parent[leader2] = leader1;
        if (rank[leader1] == rank[leader2])rank[leader1]++;
        CC--;


    }

    int getCC() {
        return CC;
    }

    int getSize(int node) {
        return groupSize[findLeader(node)];
    }
};

struct edge {
    ll w;
    int from, to;

    bool operator<(const edge &e) const {
        return e.w < w;
    }
};

vector<edge> edgList, edges;

int n, m, src, e, ans = 1e9;

double kruskal() {
    DSU d;
    double total = 0;
    priority_queue<edge> q;
    for (int i = 0; i < edgList.size(); ++i) {
        q.push(edgList[i]);
    }
    bool ok = 0;
    while (!q.empty()) {
        edge e = q.top();
        q.pop();
        if (d.mergeGroup(e.from, e.to)) {
            total += e.w;
            edges.push_back(e);
        }
    }

    return total;
};
vector<vector<int>> adj(MAX, vector<int>(MAX, 1e8));
int OO = 1e9;

bool comp(edge &a, edge &b) {
    return a.w < b.w;
}

double dist(pi x, pi y) {
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}
int adjM[MAX][MAX];
int main() {
    fast();
    int n;cin>>n;
    string arr[n];
    map<char,ll>freq;
    string march="MARCH";
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        freq[arr[i][0]]++;
    }
    ll ans=0;
    for (int j = 0; j < 5; ++j) {
        for (int i = j+1; i <5 ; ++i) {
        for (int k = i+1; k <5 ; ++k) {
            ans += (freq[march[j]] * freq[march[i]]*freq[march[k]]);
        }   }
    }
    cout<<ans;
}
