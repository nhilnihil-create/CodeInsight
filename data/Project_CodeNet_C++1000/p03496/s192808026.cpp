#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b=*max_element(a.begin(),a.end());
    int bidx=max_element(a.begin(),a.end())-a.begin();
    int l=*min_element(a.begin(),a.end());
    int lidx=min_element(a.begin(),a.end())-a.begin();
    cout << 2*n-2 << "\n";
    if(b+l>0){
        for(int i = 0; i < n; i++) {
            if(i!=bidx) cout << bidx+1 << " " << i+1 << "\n";
        }
        for(int i = 0; i < n-1; i++) {
            cout << i+1 << " " << i+2 << "\n";
        }
    }
    else{
        for(int i = 0; i < n; i++) {
            if(i!=lidx) cout << lidx+1 << " " << i+1 << "\n";
        }
        for(int i = 0; i < n-1; i++) {
            int j=n-i;
            cout << j << " " << j-1 << "\n";
        }
    }
    return 0;
}