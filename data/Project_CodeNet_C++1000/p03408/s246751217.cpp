#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    int n, m;
    cin >> n;
    vector<string> blue(n);

    rep(i, n){
        cin >> blue[i];
    }

    cin >> m;
    vector<string> red(m);
    rep(i, m){
        cin >> red[i];
    }
    int cnt=0;
    int max_cnt = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (blue[i] == blue[j]){
                cnt++;
            }
        }
        for (int l=0; l<m; l++){
            if (blue[i] == red[l]){
                cnt--;
            }
        }
        max_cnt = max(max_cnt, cnt);
        cnt = 0;
    }
    printf("%d\n", max_cnt);



}