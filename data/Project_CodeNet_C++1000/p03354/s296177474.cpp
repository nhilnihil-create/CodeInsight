#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int, int>
#define PII pair<ll, ll>
#define llu long long unsigned
#define ld long double

const ll MAX = 1e18 + 100;
const int Max = 1e9 + 500;

const int sz=1e5+100;
int pos[sz];
int par[sz], ran[sz];

void init(int n)
{
   for(int i=0;i<=n;i++) par[i]=i, ran[i]=1;
}

int Find(int x)
{
   if(par[x]==x) return x;
   else return (par[x] = Find(par[x]));
}

void Union(int x,int y)
{
   int p=Find(x);
   int q=Find(y);

   if(p == q ) return ;
   else{
       if(ran[p]> ran[q]) ran[p]+=ran[q], par[q]=p;
       else ran[q]+=ran[p], par[p]=q;
   }
}


int main()
{
   int t, i, j, k, p, q, a, b, c, mx, n, m, x;
   
   cin>>n>>m;

   init(n+1);
   for(i=1;i<=n;i++){
      cin>>x;
      pos[x]=i;
   }

   int ct=0;

   for(i=1;i<=m;i++){
      cin>>p>>q;
      Union(p, q);
   }

   for(i=1;i<=n;i++){
      if(pos[i]==i) ++ct;
      else{
          if(Find(i)==Find(pos[i])){
             ++ct;
          }
      }
   }
   
   cout<<ct<<'\n';
}