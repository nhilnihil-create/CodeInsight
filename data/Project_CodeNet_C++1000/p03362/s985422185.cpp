#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool pr_check(int x){
    for(int i = 2; i <= sqrt(x);++i){
        if(x%i == 0) return false;
    }
    return true;
}

int main(){
    int n; cin >> n;
    vector<int> a = {11,31,41,61};
    for(int i = 71; i <= 55555; i += 10){
        if(pr_check(i)) a.emplace_back(i);
        if(a.size() == n) break;
    }
    rep(i,n-1) cout << a[i] << " ";
    cout << a[n-1] << endl;
}