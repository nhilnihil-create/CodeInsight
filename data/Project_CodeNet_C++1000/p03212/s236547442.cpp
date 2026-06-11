#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i < n; i++)

typedef long long ll;

long dfs(long N, string s){
    if(stoll(s) > N) return 0;

    long count = 0;
    if(s.find("7") != string::npos && s.find("5") != string::npos && s.find("3") != string::npos){
        count = 1;
    }

    count += dfs(N, s+"7");
    count += dfs(N, s+"5");
    count += dfs(N, s+"3");

    return count;
}

int main() {
    long N; cin>>N;

    cout<<dfs(N, "0")<<endl;
}