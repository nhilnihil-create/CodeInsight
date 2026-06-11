#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const int num = pow(10, 9) + 7;

int main(){
    int N;
    cin >> N;
    map<char, int> mp;
    string S;
    cin >> S;
    rep(i, N){
        mp[S[i]]++;
    }
    ll ans = 1;
    for(auto p : mp){
        ans = (ans * (p.second + 1)) % num;
    }
    ans--;
    cout << ans << endl;
    return 0;
}