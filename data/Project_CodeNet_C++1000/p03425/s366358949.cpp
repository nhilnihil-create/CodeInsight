#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define aint(v) v.begin(),v.end()
#define endl "\n"
#define all(v) v.begin(),v.end()
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<15> MASK;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}


int main() {
    fast();
    int n;cin>>n;
    string arr[n];
    ll freq[200]={0};
    string march="MARCH";
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        freq[arr[i][0]]++;
    }
    ll ans=0;
    for (int j = 0; j < 5; ++j) {
        for (int i = j+1; i <5 ; ++i) {
        for (int k = i+1; k <5 ; ++k) {
            ans += (freq[march[j]] * freq[march[i]]*freq[march[k]]);
        }   }
    }
    cout<<ans;
}
