#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <functional>
#include <deque>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
map<int,int> depth;
vector<vector<int>> e;
void dfs(int par,int now,int num){
   depth[now] = num;
   for(int next:e[now]){
       if(next != par)dfs(now,next,num+1);
   }
}
int main(){
    int n;
    cin >> n;

    e.resize(n);
    for(int i = 0;i < n-1;i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    vector<int> c(n);
    int m = 0;
    for(int i = 0;i < n;i++){
        cin >> c[i];//ある頂点を根とした根付き木を考えて,深さが小さい順から大きい値を入れていく.
        m += c[i];
    }
    sort(c.begin(),c.end(),greater<int>());

    m -= c[0];
    dfs(-1,0,0);
    vector<pair<int,int>> vdp(n);
    for(int i = 0;i < n;i++){
        vdp[i] = make_pair(depth[i],i);
    }

    sort(vdp.begin(),vdp.end());

    map<int,int> v_val;
    for(int i = 0;i < n;i++){
        int v = vdp[i].second;
        v_val[v] = c[i];
    }

    cout << m << endl;
    for(int i = 0;i < n;i++){
        cout << v_val[i] << " ";
    }
    cout << endl;
}
