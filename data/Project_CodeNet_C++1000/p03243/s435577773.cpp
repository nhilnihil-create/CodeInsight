#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    vector<int> a;
    for(int i = 1; i < 10; i++) a.push_back(i * 111);

    for(auto x:a){
        if(x >= n){
            put(x);
            return 0;
        }
    }
}