//Be Name Khoda, Besmellah Rahmane Rahim, In The Name Of God;
//#include<bits/stdc++.h>
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include <stdio.h>
#include <string.h>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
#include <fstream>

using namespace std;

const long long N = 1e5 + 5;
long long n;
set< pair<long long, long long> > s;
vector<long long> graph[N];
long long cnt[N];
long long par[N];
long long root, maxi;
vector< pair<long long, long long> > edge;
long long check = 0;

void dfs(long long v, long long par = -1, long long h = 0)
{
    check += h;
    for (auto u: graph[v])
    {
        if (u != par)
        {
            edge.push_back({v, u});
            dfs(u, v, h + 1);
        }
    }
}


int main() 
{
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        s.insert({-tmp, i});
    }
    while (s.size())
    {
        /*
        for (auto u: s)
        {
            cout << "(" << -u.first << ", " << u.second << ") ";
        }
        cout << endl;
        */
        auto p = (*s.begin());
        s.erase(s.begin());
        long long v = p.second;
        long long w = p.first;
        w = -w;
        cnt[v]++;
        long long tmp = w + cnt[v] - (n - cnt[v]);
        if (s.size())
        {
            auto nei = s.lower_bound({-tmp, -1});
            //cout << (*nei).first << " " << (*nei).second << endl;
            if (nei == s.end() || (*nei).first != -tmp)
            {
                cout << -1 << endl;
                exit(0);
            }
            par[v] = (*nei).second;
            //cout << v << " " << par[v] << endl;
            cnt[(*nei).second] += cnt[v];
        }
        else
        {
            root = v;
            maxi = w;
        }
    }
    for (long long i = 0; i < n; i++)
    {
        if (i == root)
        {
            continue;
        }
        graph[i].push_back(par[i]);
        graph[par[i]].push_back(i);
    }
    dfs(root);
    if (check != maxi)
    {
        cout << -1 << endl;
        exit(0);
    }
    for (long long i = 0; i < n - 1; i++)
    {
        cout << edge[i].first + 1 << " " << edge[i].second + 1 << endl;
    }
    
}





