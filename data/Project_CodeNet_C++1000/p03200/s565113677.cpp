#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e5 + 77;
int A[N];
string s;
int32_t main(){
    fast;
    cin >> s;
    int n = s.size() ;
    int ans = 0 , c = 0;
    for(int i = 0; i < n ; ++i){
        if(s[i]=='B') c++;
        else ans += c;
    }
    cout << ans << endl;
    return 0;
}