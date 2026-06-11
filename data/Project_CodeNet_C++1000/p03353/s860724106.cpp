#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    string s;
    int k;
    cin >> s >> k;
    set<string> se;
    rep(i,s.size()){
        for(int j=1;j<=min((int)s.size(),k);j++){
            string t = s.substr(i,j);
            se.insert(t);
        }
    }
    auto itr = se.begin();
    k--;
    while(k--) itr++;
    cout << *itr << endl;
}