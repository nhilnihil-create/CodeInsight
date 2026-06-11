#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> t;
    int i;
    for(i=0; i<n; i++){
        int d;
        cin >> d;
        t.push_back(d);
    }
    sort(t.begin(), t.end());
    int tmp = 0, res = t[k-1]-t[0];
    for(i=1; i<n-k+1; i++){
        tmp = t[i+k-1] - t[i];
        res = min(tmp, res);
        //cout << tmp << " " << res << endl;
    }
    cout << res << endl;
    return 0;
}