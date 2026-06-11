#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d,x; cin >> n >> d >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum=x;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < d+1; j+=a[i]) {
            sum+=1;
        }
    }
    cout << sum << endl;
    return 0;
}