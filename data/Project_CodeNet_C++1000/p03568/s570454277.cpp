#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define PI (acos(-1.0))
#define MODN 1000000007
#define MODN2 998244353
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

bool next(vector<int> &v){

    int size = v.size();

    rep(i, size){
        v[i]++;

        if(v[i] == 2){
            v[i] = -1;

            if(i == size - 1) return false;
        }else{
            return true;
        }
    }

    return false;
}

int main(){

    int n;
    cin >> n;
    vector<int> a(n);

    rep(i, n){
        cin >> a[i];
    }

    vector<int> diff(n, -1);

    int ans = 0;

    do{

        bool tmp = false;
        rep(i, n){
            if((a[i] + diff[i]) % 2 == 0){
                tmp = true;
                break;
            }
        }

        if(tmp) ans++;
    }while(next(diff));

    cout << ans << endl;
    return 0;
}
