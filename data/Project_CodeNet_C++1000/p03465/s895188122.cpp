#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vii         vector<pair<int,int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define endl '\n'
#define int long long int
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int n;cin >> n;
    vi in(n);
    int sum =0;
    FOR(i, n)cin >> in[i], sum += in[i];
    const int sz = (2000*2000/2) + 2000 + 1;
    if(n == 1){
        cout << in[0];
        return 0;
    }
    bitset<sz> dp;
    bitset<sz> prev;
    prev[0] = 1;
    FOR(i, n){
        dp = prev;
        dp |= (prev << in[i]);
        swap(dp, prev);
    }
    int mid = (sum+1)/2;
    while(true){
        if(prev[mid]){
            cout << mid;
            return 0;
        }
        mid++;
    }

} 


