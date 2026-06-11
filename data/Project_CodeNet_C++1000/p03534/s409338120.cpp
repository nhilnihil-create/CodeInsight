#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << ": " << x << endl;
#define popcnt __builtin_popcount


int main() {
    string s;
    cin>>s;
    int N = sz(s);
    map<char, int> cnt;
    for(int i = 0; i < N; i++)
    {
        cnt[s[i]]++;
    }

    if(N==1){
        puts("YES");
    }else if(N==2){
        if(cnt['a']>=2||cnt['b']>=2||cnt['c']>=2)puts("NO");
        else puts("YES");
    }else{
        if(cnt['a']>=N/3&&cnt['b']>=N/3&&cnt['c']>=N/3
        &&abs(cnt['a']-cnt['b'])<=1&&abs(cnt['b']-cnt['c'])<=1&&abs(cnt['c']-cnt['a'])<=1)puts("YES");
        else puts("NO");
    }

    return 0;
}