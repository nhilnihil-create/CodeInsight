#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 100100100100;


ll combination(ll n, ll r){
    if(n < r) return 0;
    if(r == 0||r == n) return 1;
    else if(r == 1) return n;
    return (combination(n - 1, r - 1) + combination(n - 1, r));
}

bool checkKaibun(string str){
    string checkStr = str;
    reverse(checkStr.begin(), checkStr.end());
    if(str == checkStr) return true;
    else return false;
}

int keta(ll num){
    int digits = 0;
    while(num > 0){
        num /= 10;
        digits++;
    }
    return digits;
}


int main(){
    ll N;
    cin >> N;
    vector<int> a(N + 2);
    for(int i = 1; i < N + 1; i++) cin >> a[i];
    a[0] = 0;
    a[N + 1] = 0;
    int nowPos = 0;
    int sumDist = 0;
    rep(i, N){
        sumDist += abs(a[i]- a[i + 1]);
    }
    sumDist += abs(a[N] - a[0]);
    for(int i = 1; i <= N; i++){
        int ans = sumDist;
        ans -= abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]);
        ans += abs(a[i + 1] - a[i - 1]);
        cout << ans << endl;
    }
}