#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
#include <bits/stdc++.h>
int main() {
    int n;
    cin >> n;
    vector <int> a(n) , b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    int t = n / 2;
    sort(b.begin() , b.end());
    for(int i = 0; i < n; i++){
        if(a[i] < b[t]){
            cout << b[t] << endl;
        }
        else{
            cout << b[t - 1] << endl;
        }
    }
    return 0;
}
