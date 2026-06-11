
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

//n個のコマの担当範囲をどう区切るかの問題に帰着できる
//範囲を決めることは、その右端から次の担当コマまでの区間をカウントしなくてよくすることと同義
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i,m) cin >> x[i];

    int ans=0;
    vector<int> d(m-1);
    sort(all(x));
    rep(i,m-1) d[i]=x[i+1]-x[i];
    sort(all(d));
    //距離dが大きい上位n-1個のdはカウントしなくて良い
    rep(i,m-n) ans += d[i];

    cout << ans << endl;


}