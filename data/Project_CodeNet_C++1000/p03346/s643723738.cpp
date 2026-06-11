#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i,N) cin >> P[i];
    int max_len = 1;
    map<int,int> mp;
    rep(i,N){
        mp[P[i]] = mp[P[i] - 1] + 1;
    }
    for (map<int,int>::iterator itr = mp.begin(); itr != mp.end(); itr++){
        max_len = max(max_len, itr->second);
    }
    cout << N - max_len << endl;
}
