// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int m = 0;
    vector<int> a, b;    
    if(n%2){
        for(int i = 1; i < n; ++i){
            for(int j = i+1; j <= n; ++j){
                if(i+j != n){
                    a.push_back(i);
                    b.push_back(j);
                    ++m;
                }
            }
        }
    }else{
        for(int i = 1; i < n; ++i){
            for(int j = i+1; j <= n; ++j){
                if(i + j != n + 1){
                    a.push_back(i);
                    b.push_back(j);
                    ++m;
                }
            }
        }
    }

    cout << m << "\n";
    rep(i,m) cout << a[i] << " " << b[i] << "\n";

}