#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    bool ans = false;
    string s; cin >> s;
    vector<string> check;
    for(int tmp = 0; tmp < (1 << 4); tmp++){
        bitset<4> s(tmp);
        string str = "";
        if(s.test(0))str.push_back('A');
        str.push_back('K');
        str.push_back('I');
        str.push_back('H');
        if(s.test(1))str.push_back('A');
        str.push_back('B');
        if(s.test(2))str.push_back('A');
        str.push_back('R');
        if(s.test(3))str.push_back('A');
        check.push_back(str);
    }

    rep(i, check.size()){
        if(s == check[i])ans = true;
    }

    if(ans == false)cout << "NO" << endl;
    else cout << "YES" << endl;
}