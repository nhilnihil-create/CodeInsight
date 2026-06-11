#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

bool IsPrime(ll num)
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false; // 偶数はあらかじめ除く

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

int sum_of_two(ll a){
    int ans(0);
    while(1){
        if(a%2==0){
            ans++;
            a /= 2;
        }else{
            return ans;
        }
    }
}

int main(){
    int n;  cin >> n;

    int ans(0);
    rep(i,n){
        ll a;   cin >> a;
        if(a%2==0){
            ans += sum_of_two(a);
        }
    }

    cout << ans << endl;

    return 0;
}