#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
signed main(){
    int n,m;cin >>n >> m;
    vector<int> divs;
    for(int i = 1;i*i <= m;i++){
        if(m%i == 0){
            divs.push_back(i);
            if(i*i != m)divs.push_back(m/i);
        }

    }
    sort(divs.rbegin(),divs.rend());
    for(auto g:divs){
        if(m/g >= n){
            cout << g << endl;
            return 0;
        }
    }

    return 0;
}