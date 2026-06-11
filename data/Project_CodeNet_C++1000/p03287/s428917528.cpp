#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <cstdio>
#include <tuple>
#include <string>
#include <vector> 
#include <set>
#include <string.h>
#include <map>
#include <cmath>
#include <deque>
using ll = long long;
using Graph = vector<vector<int>>;
#include <queue>
#include <stack>
#include <stdlib.h>


int main(){
    int N;
    ll M;
    cin >> N >> M;

    vector<ll> a(N);
    for(int i=0;i < N;i++) cin >> a[i];

    vector<ll> s(N + 1,0);
    //累積和
    for(int i = 0;i < N;i++) s[i + 1] = (s[i] + a[i]) % M;


    //[l,r + 1)の部分和がmで割り切れる数
    ll cnt = 0LL;
    // for(int i = 0;i < n;i++){
         
    //     for(int j = i + 1;j < n + 1;j++){
    //         if((s[j] - s[i]) % m == 0LL) cnt++;

    //     }

    // } 
    map<ll,ll> mp;
    for(int i = 0;i < s.size();i++){
        cnt += mp[s[i]];
        mp[s[i]]++;


    }
    cout << cnt << endl;

    return 0; 
}