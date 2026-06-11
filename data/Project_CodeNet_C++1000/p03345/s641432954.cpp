#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(),v.end()
ll INF = 10010001010;

ll lcm(ll a,ll b)
{
    return a * b / __gcd(a, b);
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
    ll A, B, C, K;
    cin >> A>>B>>C>>K;
    if(abs(A-B) > 1000000000000000000){
        cout << "Unfair" << endl;
    }
    else{
        if(K%2 == 0){
            cout << A - B << endl;
        }
        else{
            cout << B - A << endl;
        }
    }
}
