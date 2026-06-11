#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

//解説放送見て回答

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        if(n <= k + (k - 1) * (i - 1)){
            put(i);
            return 0;
        }
    }
}