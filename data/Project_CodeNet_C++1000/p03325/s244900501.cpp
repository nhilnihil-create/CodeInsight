#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    bool flag = false;
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        while(a[i]%2 == 0){
            a[i] /= 2;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}