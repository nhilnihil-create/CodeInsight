#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    int a,b,k;
    cin >>a>>b>>k;
    for (int i = 0; i < k; ++i) {
        if(a+i<=b) {
            cout << a + i << endl;
        }
    }
    for (int i = 0; i < k; ++i) {
        if(b-k+i+1>=a+k) {
            cout << b - k + i + 1 << endl;
        }
    }
    return 0;
}

