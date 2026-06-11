#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define print(obj) cout << obj << endl
#define scan(obj) cin >> obj

typedef long long ll;

using namespace std;

bool IsPrime(int num);

int main(void){
    ll n, p, temp = 2, ans = 1;
    vector<int> soinsu;
    cin >> n >> p;
    if(p == 1){
        print(1);
        return 0;
    }
    if(n == 1){
        print(p);
        return 0;
    }
    while(p >= temp * temp/*!IsPrime(p)*/){
        bool flag = true;
        if(p % temp == 0){
            soinsu.pb(temp);
            p /= temp;
            flag = false;
            continue;
        }
        temp++;
    }
    soinsu.pb(p);
    int tyouhuku = 1;
    rep(i, soinsu.size() - 1){
        if(soinsu[i] == soinsu[i + 1]){
            tyouhuku++;
        } else {
            tyouhuku = 1;
        }
        if(tyouhuku == n){
            ans *= soinsu[i];
            i++;
            tyouhuku = 1;
        }
    }
    print(ans);
}

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}