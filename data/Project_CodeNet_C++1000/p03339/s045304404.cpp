#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()
template <typename T>
inline T gcd(T a, T b) { while (b != 0) swap(b, a %= b); return a; }

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> e(n);
    vector<int> w(n);

    if(s[0]=='W')
        w[0]=1;
    for(int i=1; i<n; ++i){
        if(s[i]=='W')
            w[i] = w[i-1]+1;
        else
            w[i] = w[i-1];
    }


    if(s[n-1]=='E')
        e[n-1]=1;
    for(int i=n-2; i>=0; --i){
        if(s[i]=='E')
            e[i] = e[i+1]+1;
        else
            e[i] = e[i+1];
    }

    int ans = INT_MAX;
    for(int i=0; i<n; ++i){
        ans = min(ans, e[i]+w[i]-1);
    }
    cout << ans;
}