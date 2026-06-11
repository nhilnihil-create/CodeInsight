#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> odd;
    map<int, int> even;

    int max_odd = 0, max_even = 0;
    int second_odd = 0, second_even = 0;
    int sum_odd = 0, sum_even = 0;
    int odd_v, even_v;
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        if(i % 2 == 0){
            odd[v]++;
            if(max_odd < odd[v]){
                max_odd = odd[v];
                odd_v = v;
            }
            else if(second_odd < odd[v]){
                second_odd = odd[v];
            }
            sum_odd++;
        }
        else{
            even[v]++;
            if(max_even < even[v]){
                max_even = even[v];
                even_v = v;
            }
            else if(second_even < even[v]){
                second_even = even[v];
            }
            sum_even++;
        }
    }

    if(odd_v != even_v){
        sum_odd -= max_odd;
        sum_even -= max_even;
        cout << sum_odd + sum_even << endl;
    }
    else{
        int t1 = sum_odd - max_odd + sum_even - second_even;
        int t2 = sum_odd - second_odd + sum_even - max_odd;
        cout << min(t1, t2) << endl;
    }
    return 0;
}