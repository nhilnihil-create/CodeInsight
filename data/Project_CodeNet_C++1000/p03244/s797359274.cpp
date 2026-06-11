#include <bits/stdc++.h>
using namespace std;
const int MAX = 101000;

void solve(long long n, vector<long long> v){
    vector<int> odd_hist(MAX, 0), even_hist(MAX, 0);
    for(int i = 0; i < n; ++i){
        if(i % 2 == 0) even_hist[v[i]]++;
        else odd_hist[v[i]]++;
    }
    vector<pair<int, int> > odd, even;
    for(int i = 0; i < MAX; ++i){
        odd.push_back(pair<int, int>(odd_hist[i], i));
        even.push_back(pair<int, int>(even_hist[i], i));
    }
    sort(odd.begin(), odd.end(), greater<pair<int, int>>());
    sort(even.begin(), even.end(), greater<pair<int, int>>());
    if(odd[0].second != even[0].second){
        cout << n - odd[0].first - even[0].first << endl;
    }
    else{
        cout << n - max(odd[0].first + even[1].first, odd[1].first + even[0].first) << endl;
    }
    return;
}

int main(){
    long long n;
    scanf("%lld",&n);
    std::vector<long long> v(n);
    for(int i = 0 ; i < n ; i++){
        scanf("%lld",&v[i]);
    }
    solve(n, std::move(v));
    return 0;
}
