#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    int n, m;
    cin >> n >> m;
    vi food(m, 0);
    rep(i, n){
        int k;
        cin >> k;
        rep(j, k){
            int tmp;
            cin >> tmp;
            food[tmp-1]++;
        }
    }
    int cnt = 0;
    rep(i, m){
        if(food[i] == n) cnt++;
    }
    cout << cnt << endl;
    return 0;
}