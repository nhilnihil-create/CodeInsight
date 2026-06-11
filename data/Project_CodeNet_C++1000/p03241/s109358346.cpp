#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;



int main(){
    int n, m; cin >> n >> m;
    vector<int> divisor;
    for(int i = 1; i * i <= m; ++i){
        if(m % i == 0){
            divisor.push_back(i);
            if(i*i != m) divisor.push_back(m/i);
        }
    }    
    sort(ALL(divisor));
    for(auto elem : divisor){
        if(elem < n) continue;
        cout << m/elem << endl;
        return 0;
    }
    return 0;
}