#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)

int main(void){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    vector<vector<bool>> check(n, vector<bool>(m, false));

    roop(i, n){
        int k; cin >> k;
        roop(j, k){
            int a; cin >> a;
            check[i][a-1] = true;
        }
    }


    int ans = 0;

    roop(i, m){
        bool tmp = true;
        roop(j, n){
            if(check[j][i] == false) tmp = false;
        }
        if(tmp) ans++;
    }
    
    cout << ans << endl;

    return 0;
}