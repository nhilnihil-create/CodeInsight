#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;




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

int digNum(ll x, int n){
    ll num = pow(10, n - 1);
    num = x / num;
    num %= 10;
    return num;
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
    //頭から1引いて残りを9で埋めたやつ
    ll N;
    cin >> N;
    vector<int> a;
    int k = keta(N);
    for(int i = 0; i < k; i++){
        a.push_back(digNum(N, k - i));
    }
    int ans1 = 0;
    rep(i, k){
        ans1 += a[i];
    }
    int ans2 = a[0] - 1;
    rep(i, k - 1)ans2 +=9;
    cout << max(ans1, ans2) << endl;

}
