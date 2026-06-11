#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    int N, M;
    cin >> N >> M;
    cout << (1900 * M + 100 * (N - M)) * pow(2, M) << endl;
}