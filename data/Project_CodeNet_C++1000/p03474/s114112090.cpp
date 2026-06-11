#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main(){
    int a, b; cin >> a >> b;
    string s; cin >> s;
    bool isOK = true;
    for(int i = 0; i < s.size(); ++i){
        if(i != a && s[i] == '-') isOK = false;
        if(s[a] != '-') isOK = false; 
    }
    if(isOK) cout << "Yes" << endl;
    else cout << "No" << endl;
}