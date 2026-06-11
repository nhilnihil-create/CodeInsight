// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a, b;

    for(int i = 1; i < n; ++i){
        for(int j = i+1; j <= n; ++j){
            if((n%2 == 1 && i+j != n) || (n%2 == 0 && i+j != n+1)){
                a.push_back(i);
                b.push_back(j);
            }
        }
    }

    cout << a.size() << "\n";
    rep(i,a.size()) cout << a[i] << " " << b[i] << "\n";
}