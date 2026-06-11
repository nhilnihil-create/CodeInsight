#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a){
        cin >> i;
        i--;
    }
    vector <int> p(n);
    for(int i = 0 ; i < n ; i++){
        p[a[i]] = i;
    }
    int ans = 1;
    int cur = 1;
    for(int i = n - 2 ; i >= 0 ; i--){
        if(p[i + 1] < p[i]) cur = 1;
        else cur++;
        ans = max(ans, cur);
    }
    cout << n - ans << endl;
}
