#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

vector<int> prime(int n){
    vector<int> res(100,0);
    for(int i=2; i*i<=n; i++){
        while(n%i == 0){ res[i]++; n /= i; }
    }
    if(n>1) res[n]++;
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> data(100,0);
    loop(i,1,n+1) rep(j,101) data[j] += prime(i)[j];
    int a3 = 0, a5 = 0, a15 = 0, a25 = 0, a75 = 0;
    rep(i,101){
        if(2 <= data[i] && data[i] < 4) a3++;
        else if(4 <= data[i] && data[i] < 14) a5++;
        else if(14 <= data[i] && data[i] < 24) a15++;
        else if(24 <= data[i] && data[i] < 74) a25++;
        else if(74 <= data[i]) a75++;
    }
    int ans = a3*(a5+a15+a25+a75)*(a5+a15+a25+a75-1)/2;
    ans += (a5+a15+a25+a75)*(a5+a15+a25+a75-1)*(a5+a15+a25+a75-2)/2;
    ans += (a15+a25+a75)*(a5+a15+a25+a75-1);
    ans += (a25+a75)*(a3+a5+a15+a25+a75-1);
    ans += a75;
    cout << ans << endl;
}