#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    string s;
    cin >> s;
    int n = s.length();

    if(s[0]=='0' || s[n-2]=='0' || s[n-1]=='1'){
        cout << "-1\n";
        return;
    }
    for(int i = 0; i < n-1; ++i){
        if(s[i]!=s[n-2-i]){
            cout << "-1\n";
            return;
        }
    }

    vector<pair<int, int>> ans;
    int head = 1;
    for(int i = 0; i < n-1; ++i){
        int last = i+2;
        if(s[i]=='1'){
            ans.push_back({last, head});
            head = last;
        }
        else{
            ans.push_back({head, last});
        }
    }

    for(auto& a : ans){
        cout << a.F << " " << a.S << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}