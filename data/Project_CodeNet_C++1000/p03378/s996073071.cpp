#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    int itr = 0;
    rep(i, m) {
        cin >> a[i];
        if(a[i] < x) itr++;
    }
    int right = m - itr;
    if(right < itr){
        cout << right << endl;
    }else{
        cout << itr << endl;
    }


}
