
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()


int main(){
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    rep(i,n) cin >> m[i];

    //最低1つずつは作る
    int ans=n;
    rep(i,n){
        x -= m.at(i);
    }

    //昇順に並び替え、一番必要量が少ないものを限界まで作る
    sort(all(m));
    while(true){
        if(m.at(0) <= x){
            ans ++;
            x -= m.at(0);
        }
        else{
            cout << ans << endl;
            return 0;
        }
    }

}