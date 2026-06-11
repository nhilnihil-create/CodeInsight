#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sp pair<string,string>

int N;
string S;
unordered_map<string,int> mp;

void dfs1(string r, string b, int idx){
    if(idx == N){
        mp[r + ' ' + b]++;
    }else{
        dfs1(r + S[idx], b, idx + 1);
        dfs1(r, b + S[idx], idx + 1);
    }
}

ll dfs2(string r, string b, int idx){
    if(idx == N - 1){
        return mp[r + ' ' + b];
    }else{
        return dfs2(r + S[idx], b, idx - 1) + dfs2(r, b + S[idx], idx - 1);
    }
}

int main(){
    cin >> N >> S;

    dfs1("", "", 0);
    cout << dfs2("", "", 2 * N - 1) << endl;
    return 0;
}