#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> m(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> m[i];
        sum += m[i];
    }
    x -= sum;
    sort(m.begin(),m.end());
    int a = m[0];

    cout << n + x/a << endl;
}