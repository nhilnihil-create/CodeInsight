#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>

ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}
ll INF = 10010001010;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int L = A + B, R = C + D;
    if(L > R){
        cout << "Left" << endl;
    }
    else if(L < R){
        cout << "Right" << endl;
    }
    else{
        cout << "Balanced" << endl;
    }
}
