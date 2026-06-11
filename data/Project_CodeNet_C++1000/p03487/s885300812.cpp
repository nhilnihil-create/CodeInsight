#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    int n;
    cin >> n;
    map <int,int> table;
    vector <int> kind(0);

    rep(i,n){
        int a;
        cin >> a;
        if(table.count(a)){
            table.at(a)++;
        }
        else{
            table[a] = 1;
            kind.push_back(a);
        }
    }

    int ans;
    for(int x:kind){
        if(table.at(x) <  x){
            ans += table.at(x);
        }
        if(table.at(x) > x){
            ans += (table.at(x)-x);
        }
    }

    cout << ans << endl;
}