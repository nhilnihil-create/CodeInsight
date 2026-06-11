#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


//ABC 114 c

vector<char> lis = {'3','5','7'};
int dfs(string S,ll n){
    int res = 0;

    if(S.size()>0){
        if(stoll(S) > n) return res;
        bool flag = true;
        for(auto c : lis){
            if(S.find(c) == string::npos) flag = false;
        }
        if(flag) res++;
    }

    for(auto c : lis){
        S.push_back(c);
        res += dfs(S,n);
        S.pop_back();
    }

    return res;
}


int main(){
    ll n;
    cin >> n;
    string s = "";
    int count = dfs(s,n);
    cout << count << endl;
}


