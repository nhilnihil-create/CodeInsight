#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), ans;
    rep(i,n) cin >> a[i], --a[i];
    rep(i,n) {
        int temp = -1;
        for(int j = a.size()-1; j >= 0; --j){
            if(a[j]==j){
                temp = j;
                break;
            }
        }
        if(temp==-1){
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(temp+1);
        a.erase(a.begin()+temp);
    }
    reverse(all(ans));
    for(int x : ans){
        cout << x << endl;
    }
    return 0;
}