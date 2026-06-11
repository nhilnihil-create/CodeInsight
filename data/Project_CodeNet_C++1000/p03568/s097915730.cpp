#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    ll ss=1;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        if(!(a[i]&1))
            ss *= 2;
    }
    cout << pow(3,n) - ss;
}
