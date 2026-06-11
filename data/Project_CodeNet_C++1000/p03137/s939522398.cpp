#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using ll = long long;
using namespace std;
int x, y, z, l, m, n, r=0, q, k;

void solve() {
    cin>>n>>m;
    vector<int> dist(m, 0);
    for(int i=0;i<m;i++){
        cin>>dist[i];
    }
    int dsum=0;
    sort(dist.begin(), dist.end());
    for(int i=0;i<m-1;i++){
        dist[i]= dist[i+1]- dist[i];
        dsum+=dist[i];
    }
    dist.resize(m-1);
    sort(dist.begin(), dist.end());
    int cnt=0;
    for(int i=0;i<m-n;i++){

        cnt+=dist[i];
    
    }
    cout<<cnt;
}

int main() 
{
    std::ios::sync_with_stdio(false); \
        std::cin.tie(NULL);
    int test;
    test  =1 ;
    while (test--) {
        solve();
    }
    return 0;
}