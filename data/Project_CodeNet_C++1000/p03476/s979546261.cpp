#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

bool is_prime(int n){
    if(n < 2) return false;
    else if(n == 2) return true;
    else if(n % 2 == 0) return false;

    for(int i = 3; i <= sqrt(n); i += 2){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

int main(void){
    int q;
    cin >> q;

    int a[100005], sum = 0;
    for(int i = 0; i < 100005; ++i){
        if(is_prime(i) && is_prime((i+1)/2)) sum++;
        a[i] = sum;
    }

    vector<int> ans(q);
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        ans[i] = a[r] - a[l-1];
    }

    for(int i = 0; i < q; ++i){
        cout << ans[i] << "\n";
    }

//    for(int i = 1; i < 10; ++i){
//        cout << i << " " << a[i] << "\n";
//    }

    return 0;
}
