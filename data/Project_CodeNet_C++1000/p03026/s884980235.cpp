#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

const ll MOD = INF + 7;



int main(){
    int n;
    cin >> n;
    Graph G(n);
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    VEC(int, c, n);
    sort(ALL(c), greater<int>());

    queue<int>que;
    que.push(0);

    vector<int>r(n, -1);
    int now = 0;
    while(!que.empty()){
        int v = que.front();
        r[v] = c[now];
        now++;
        que.pop();

        for(int nv : G[v]){
            if(r[nv] != -1)continue;
            que.push(nv);
        }
    }

    reverse(ALL(c));
    int sum = 0;
    rep(i, n - 1)sum += c[i];
    cout << sum << endl;
    rep(i, n)cout << r[i] << " ";
}