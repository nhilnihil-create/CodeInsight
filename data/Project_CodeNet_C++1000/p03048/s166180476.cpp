#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define _rep(i,m,n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;
const ll mod = 1000000007;
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main(){
    int r,g,b,n; cin >> r >> g >> b >> n;
    int count = 0;
    int m = n;
    vector<int> B(m + 1);
    rep(i,m + 1) B[i] = i * b;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(binary_search(B.begin(), B.end(), n - r * i - g * j)){
                count++;
                //cout << i << " " << j << " " << (n - r * i - g * j) / b << endl;
            }
        }
    }
    cout << count << endl;
}