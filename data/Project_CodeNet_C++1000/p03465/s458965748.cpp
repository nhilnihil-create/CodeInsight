#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 4e6+5;
bitset<N> b;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++) cin>>a[i];

    int sum = 0;
    b.set(0);
    for (auto x:a){
        sum += x;
        b |= b<<x;
    }

    int mid = (sum+1)/2;

    for (;;mid++){
        if (b[mid]){
            cout<<mid<<endl;
            return 0;
        }
    }

    return 0;
}

