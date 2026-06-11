#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // cumulative sum
    vector<long long int> sa(n+1);
    for(int i=0; i<n; i++){
        sa[i+1] = sa[i] + a[i];
    }

    map<long long int, long long int> count;
    for(int i=0; i<n+1; i++){
        //cout << sa[i] << " ";
        if(count.find(sa[i]) == count.end()) count[sa[i]] = 1;
        else count[sa[i]] += 1;
    }

    long long int ans = 0;
    for(auto c : count){
        ans += c.second * (c.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}