#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int n, tmp1;
vector<iii> edges;

signed main(){
    cin >> n;
    int tmp = log2(n);
    for(int i = 1; i <= tmp; i++){
        edges.pb({{i, i + 1}, 1 << (i - 1)});
    }
    for(int i = 1; i < 20; i++) edges.pb({{i, i + 1}, 0});
    tmp1 = (1 << (tmp));
    n -= tmp1;
    for(int i = 20; i >= 0; i--){
        if(n & (1 << i)){
            edges.pb({{i + 1, 20}, tmp1});
            tmp1 += 1 << i;
        }
    }
    cout << 20 << " " << edges.size() << "\n";
    for(int i = 0; i < edges.size(); i++) cout << edges[i].first.first << " " << edges[i].first.second << " " << edges[i].second << "\n";
}