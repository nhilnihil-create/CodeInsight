#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define REP(NAME, NUM) for (int NAME = 0; NAME < (NUM); ++NAME)
#define BREP(NAME, NUM) for (int NAME = (NUM)-1; NAME >= 0; --NAME)
#define VEC(TYPE, A, NAME, INIT) vector<TYPE> NAME(A, INIT)
#define VEC2(TYPE, A, B, NAME, INIT) vector<vector<TYPE>> NAME(A, vector<TYPE>(B, (INIT)))

int main()
{
    int n;
    cin >> n;
    struct Node{
        int idx = -1;
        ull cost = 1;
        ull costSum = 0;
    };
    map<ull, Node> mp;
    REP(i, n) 
    {
        ull a;
        cin >> a;
        mp[a].idx = i;
    }

    struct Edge{
        int i;
        int j;
    };
    VEC(Edge, 0, edgeAry, Edge());
    for( auto it = mp.rbegin(); it != mp.rend(); ++it )
    {
        const ull d = it->first;
        Node& node = it->second;

        if( d == mp.begin()->first ) break;
        ull sub = n - 2*node.cost;

        auto& nextNode = mp[d-sub];
        if( nextNode.idx == -1 )
        {
            cout << -1 << endl;
            return 0;
        }
        nextNode.cost += node.cost;
        nextNode.costSum += node.cost + node.costSum;

        Edge edge;
        edge.i = node.idx;
        edge.j = nextNode.idx;
        edgeAry.push_back( edge );
    }
    
    {
        const ull d = mp.begin()->first;
        Node& node = mp.begin()->second;
        
        if( node.costSum != d )
        {
            cout << -1 << endl;
            return 0;
        }
    }

    for( auto& e : edgeAry )
    {
        cout << e.i + 1 << " " << e.j + 1 << endl;
    }

    return 0;
}