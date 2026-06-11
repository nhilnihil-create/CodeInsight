#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    vector<int> a(3);
    rp(i,3) cin >> a[i];
    sort(a.begin(),a.end());
    cout << a[0]*a[1]/2 << endl;
}