#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;
char clist[] = {'M', 'A', 'R', 'C', 'H'};

int main(){
    int N;
    cin >> N;
    map<char, int> m;
    rep(i, N){
        string str;
        cin >> str;
        rep(j, 5){
            if(str[0] == clist[j]){
                m[clist[j]]++;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 4; j++){
            for(int k = j + 1; k < 5; k++){
                ans += (ll)m[clist[i]] * (ll)m[clist[j]] * (ll)m[clist[k]];
            }
        }
    }
    cout << ans << endl;
}
