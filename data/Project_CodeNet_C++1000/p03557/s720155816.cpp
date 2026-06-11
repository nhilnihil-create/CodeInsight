#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    for(int i = 0; i < n; i++){
        cin >> b.at(i);
    }
    for(int i = 0; i < n; i++){
        cin >> c.at(i);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long long int res = 0;
    long long int min = 0;
    long long int max = 0;
    for(int i = 0; i < n; i++){
        //min = lower_bound(a.begin(), a.end(), b[i]);
        min = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        //max = n - upper_bound(c.begin(), c.end(), b[i]);
        max = n - (upper_bound(c.begin(), c.end(), b[i]) - c.begin());
        res += min * max;
    }
    cout << res << endl;
}
