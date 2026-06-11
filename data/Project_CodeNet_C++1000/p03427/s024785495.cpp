#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 200005;
const int mod = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int sum = 0;
    for (auto i:s) {
        sum += i - '0';
    }
    cout << max(9 * (int)(s.size() - 1) + s[0] - '0' - 1,sum) << '\n';
}