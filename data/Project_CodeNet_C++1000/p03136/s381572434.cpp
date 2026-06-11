#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;
    vector<int> l(n);
    int max_l = 0;
    int sum_l = 0;
    int index;
    for(int i = 0; i < n; i++){
        cin >> l[i];
        sum_l += l[i];
        if(max_l < l[i]){
            max_l = l[i];
            index = i;
        }
    }
    if(max_l < sum_l - l[index]) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}