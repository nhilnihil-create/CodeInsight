#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
 
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define PI acos(-1.0)
const int N=1e5 + 5;
const int M=1e5 + 5;

vector <int> v[N];
bool vis[N];
bool ok;
vector <int> f;
int clr[N];

void dfs(int s,int c)
{
    f.pb(s);
    vis[s]=true;
    clr[s]=c;
    for(auto x:v[s]){
        if(!vis[x]){
            dfs(x,(c+1)%2);
        }
        else{
            if(clr[x]==clr[s]) ok=false;
        }
    }
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    } 
    for(i=1;i<=n;i++){
        vis[i]=false;
    }
    ll ans = 0;
    for(i=1;i<=n;i++){
        if(!vis[i]){
            f.clear();
            ok=true;
            dfs(i,0);
            ll lu = (ll)f.size();
            if(ok){
                ll c1=0,c2=0;
                for(int x:f){
                    if(clr[x]==1) c1++;
                    else c2++;
                }
                ans += c1*c2;
            }
            else{
                ans += (lu*(lu-1))/2;
            }
        }
    }

    cout << ans-m << endl;
 
    return 0;
}