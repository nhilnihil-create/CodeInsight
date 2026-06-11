#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int, int>
#define PII pair<ll, ll>
#define llu long long unsigned
#define ld long double

const ll MAX = 1e18 + 100;
const ll Max = 1e9 + 500;
const int sz=510;

struct node
{
   int a,b,c,d;
};

vector<node> ans; 
int ara[sz][sz], n, m;

bool check(int x,int y)
{
   if(ara[x][y] % 2==0) return true;
   else return false;
}

void DFS(int x,int y,int plus)
{
   if(x>n) return ;
   node temp;

   if((y==1 && plus==0) || (y==m && plus==1)){
      if(check(x,y));
      else{
          if(x+1<=n) {
             temp.a=x,temp.b=temp.d=y, temp.c=x+1;
             ara[x+1][y]+=1;
             ans.push_back(temp);
          }
      }
      
      return DFS(x+1,y,plus^1);
   }

   if(check(x,y)==false){
        if(plus==1) {
           ara[x][y+1]+=1;
           temp.a=temp.c=x, temp.b=y, temp.d=y+1;
        }
        else{
           ara[x][y-1]+=1;
           temp.a=temp.c=x, temp.b=y, temp.d=y-1;
        }
        ans.push_back(temp);
   }

   if(plus==1) return DFS(x,y+1,plus);
   else return DFS(x,y-1,plus);
}

int main()
{
   int  t, i, j, k, p, q, a, b, c, mx, x, y;
   
   cin>>n>>m;

   for(i=1;i<=n;i++){
      for(j=1;j<=m;j++) cin>>ara[i][j];
   }

   
   DFS(1,1,1);

   cout<<ans.size()<<'\n';
   for(auto xx : ans) cout<<xx.a<<" "<<xx.b<<" "<<xx.c<<" "<<xx.d<<'\n';
   
}