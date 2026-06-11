#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    int count = 0;
    long long int total = 0;
    multiset<long long int> pool;

    for(int i=0; i<n; i++){
        if(a[i] < b[i]){
            count += 1;
            total += b[i] - a[i];
        }
        if(a[i] > b[i]) pool.insert(a[i] - b[i]);
    }

    while(total > 0 && pool.empty() == false){
        total -= *prev(pool.end());
        count += 1;
        pool.erase(prev(pool.end()));
    }
    if(total > 0) cout << -1 << endl;
    else cout << count << endl;
    return 0;
}