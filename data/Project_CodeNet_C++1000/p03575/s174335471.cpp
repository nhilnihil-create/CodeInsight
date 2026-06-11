#include<bits/stdc++.h>
#define INF 1e7

using namespace std;
typedef long long int ll;

vector<int>par,len;

int find(int x)
{
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(len[x] < len[y]) par[x] = par[y];
    else par[y] = par[x];
    if(len[x] == len[y]) len[x]++;
}

int main()
{
   int N,M; cin >> N >> M;
   vector<pair<int,int>>dp;
   for(int i = 0; i < M; i++)
   {
       int a,b; cin >> a >> b;
       a--,b--;
       dp.push_back(pair(a,b));
   }
   int ans = 0;
   for(auto x:dp)
   {
       len.assign(N,0);
       par.resize(N);
       for(int i = 0; i < N; i++) par[i] = i;
       for(auto y:dp)
       {
           if(x == y) continue;
           unite(y.first,y.second);
       }
       bool f = true;
       for(int i = 0; i < N; i++) par[i] = find(i);
       for(int i = 0; i < N; i++)
       {
           for(int j = 0; j < N; j++)
           {
               if(par[i] != par[j]) f = false;
           }
       }
       if(f) ans++;
   }
   cout << M - ans << endl;
}