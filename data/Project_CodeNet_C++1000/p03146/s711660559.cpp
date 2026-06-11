#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    int s;
    cin>>s;
    vector<bool> check(1000000, false);
    int a = s;
    check[a-1] = true;
    for(int i=2;;i++){
        if(a%2 == 0) a = a/2;
        else a = 3*a+1;
        if(check[a-1]){
            cout << i << endl;
            return 0;
        }
        check[a-1] = true;
    }
}
