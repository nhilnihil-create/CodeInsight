#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = ll(1e8+7);
const ll MAX_N = ll(1e5 + 5);
const ll INF = LLONG_MAX;
#define REP(i, n) for (int i = 0; i < n; i++)


int main() {
    int n, k=2;
    cin >> n;
    while(n > k*(k-1)/2)k++;
    if(n == k*(k-1)/2){
        cout << "Yes" << endl;
        vector<vector<int> > g(k);
        int cnt = 1;
        for(int i = 0; i < k; i++){
            for(int j = i+1; j<k; j++){
                g[i].push_back(cnt);
                g[j].push_back(cnt);
                cnt++;
            }
        }
        cout << k << endl;
        REP(i,k){
            printf("%d",g[i].size());
            for(auto v : g[i]){
                printf(" %d",v);
            }
            printf("\n");
        }
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
