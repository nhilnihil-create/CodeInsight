#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
//stoi(s) : string→int stoll(s) :string→longlong  int→string to_string(i)
const double PI = acos(-1.0);
//小数点の表し方 cout << fixed << setprecision(5);
const int MAXN = 100010;
ll dp[MAXN] = {0};
bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; ll(i) <= ll(sqrtNum); i += 2)
    {
        if (num % ll(i) == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main(){
    int q;
    cin >> q;
    vector<ll> l(q),r(q);
    for(int i=0;i<q;i++){
        cin >> l[i] >> r[i];
    }
    dp[1] = 0;
    for(int i=3;i<MAXN;){
        ll p1 = ll(i),p2 = (p1 + 1) / 2;
        if(IsPrime(p1) && IsPrime(p2)){
            dp[i] = dp[i-2] + 1;
        }
        else{
            dp[i] = dp[i-2];
        }
        i+=2;
    }
    /*
    for(int i=1;i<=15;){
        cout << i << " " << dp[i] << endl; 
        i+=2;
    }
    */
    for(int i=0;i<q;i++){
        cout << dp[r[i]] - dp[l[i] - 2] << endl;
    }

}