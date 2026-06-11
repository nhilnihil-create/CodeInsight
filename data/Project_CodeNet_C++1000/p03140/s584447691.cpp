#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<queue>
#include <climits>
#include <map>
const int mod = 1e9 + 7;
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;

template<class T>
bool chmin(T &a, T b)
{
    if(a>b){
        a = b;
        return true;
    }
    return false;
}

long long dp[100001];

int main()
{
    int n;
    string a,b,c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt[26] = {0};
        cnt[a[i]-'a']++;
        cnt[b[i]-'a']++;
        cnt[c[i]-'a']++;
        int k = 0;
        for(int j = 0; j < 26; j++){
            k = max(cnt[j],k);
        }
        ans += (3-k);
    }   
    cout << ans;
}