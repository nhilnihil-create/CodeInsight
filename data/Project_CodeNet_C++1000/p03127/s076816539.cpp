#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    int x=a[0];
    while(a.size()>1){
        for(int i = 1; i < a.size(); i++) {
            a[i] %= x;
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        while(true){
            int p=a.size()-1;
            if(a[p]==0){
                a.pop_back();
            }
            else break;
        }
        sort(a.begin(),a.end());
        x=a[0];
    }

    cout << x << endl;

    return 0;
}