#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq  priority_queue<double, std::vector<double>, std::greater<double>>

int lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};







int main(){
    int N;
    cin >> N;
    int X;
    cin >> X;
    vector<int> A(N);
    for (int i = 0; i < N;i++)
    {
        cin >> A[i];
    }
    ll ans = 0;
    sort(A.begin(), A.end());
    
    for (int i = 0; i < N;i++)
    {
        if(i != N-1){
            if(A[i] <= X){
                X -= A[i];
                ans++;
            }
            else{
                break;
            }
        }
        else{
            if(A[i] == X){
                ans++;
                X -= A[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
