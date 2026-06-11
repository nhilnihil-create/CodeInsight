#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;

    map <ll,ll> table;  //<種類、枚数>
    vector <ll> num(0); //種類

    rep(i,n){
        ll a;
        cin >> a;
        if(!table.count(a)){
            table[a] = 1;
            num.push_back(a);
        }
        else{
            table.at(a) ++;
        }
    }

    rep(i,m){
        ll b,c;
        cin >> b >> c;
        if(!table.count(c)){
            table[c] = b; 
            num.push_back(c);
        }
        else{
            table.at(c) += b;
        }
    }

    sort(all(num));
    reverse(all(num));  //大きい順

    int sum = 0;    //枚数の合計
    int cur = 0;    //次のite
    ll ans = 0;     //和
    while(sum < n){
        if(sum + table.at(num[cur]) <= n){
            ans += num[cur] * table.at(num[cur]);
            sum = sum + table.at(num[cur]);
            cur ++;
        }
        else{
            ans += num[cur] * (n-sum);
            break;
        }
    }

    cout << ans << endl;
}