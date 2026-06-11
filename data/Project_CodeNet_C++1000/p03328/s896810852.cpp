#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int a,b;
    cin >> a >> b;
    map<int,int> mp;
    int now = 0;
    for(int i=1;i<=999;++i){
        now+=i;
        mp[now]=i;
    }
    
    for(int i=1;i<=499500;++i){
        if((mp[b+i] - mp[a+i]) == 1 && mp[a+i] != 0){
            cout << i << endl;
            return 0;
        }
    }
}
