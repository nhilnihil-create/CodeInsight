#include <math.h>
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <iostream>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;


int main()
{
    int N, M;
    cin >> N >> M;
    map<int, set<pair<int, int>>> OUT;
    map<int, set<int>> IN;
    set<int> start;
    FOR (i,0,N){
        start.insert(i);
    }
    FOR(i,0,N+M-1){
        int a, b;
        cin >> a >> b;
        start.erase(b - 1);
        OUT[a - 1].insert(make_pair(i, b - 1));
        IN[b - 1].insert(i);
    }
    vector<int> P(N, 0);
    while (start.size()>0){
        int now = *start.begin();
        start.erase(now);
        for (auto x:OUT[now]){
            int b = x.first;
            int nex = x.second;
            IN[nex].erase(b);
            if (IN[nex].size()==0){
                start.insert(nex);
                P[nex] = now + 1;
            }
        }
    }
    FOR(i,0,N){
        cout << P[i] << endl;
    }
}
