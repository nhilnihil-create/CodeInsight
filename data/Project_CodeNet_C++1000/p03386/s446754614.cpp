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
    ios_base::sync_with_stdio(false);cin.tie(0);
    int a, b, k;
    cin >> a >> b >> k;
    set<int> ans;
    for(int i=0; i<k; ++i){
        ans.insert(a+i);
        ans.insert(b-i);
    }
    for(auto x: ans)
        if(x>=a && x<=b)
            cout << x << endl;
    return 0;
}
