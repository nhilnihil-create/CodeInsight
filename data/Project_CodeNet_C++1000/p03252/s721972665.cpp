#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

//　T、S内の同じ文字の個数は一致する
int main(){
    string S, T;
    cin >> S >> T;
    VL v1(26, 0), v2(26, 0);
    for(auto s : S) v1[s-'a']++;
    for(auto t : T) v2[t-'a']++;
    sort(ALL(v1));
    sort(ALL(v2));
    rep(i, 0, v1.size()){
        if(v1[i] != v2[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
