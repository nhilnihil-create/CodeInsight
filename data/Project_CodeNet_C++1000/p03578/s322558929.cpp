#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n;
    vector<int> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    cin >> m;
    vector<int> t(m);
    for(int i = 0; i < m; i++){
        cin >> t[i];
    }
    sort(d.begin(), d.end());
    sort(t.begin(), t.end());
    int j = 0;
    for(int i = 0; i < n; i++){
        if(j == m){
            break;
        }
        if(d[i] < t[j]){
            continue;
        } else if (d[i] == t[j]) {
            j++;
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}