#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
    vi a(2);
    int k;
    cin>>a[0]>>a[1]>>k;
    
    rep(i,k){
        if(a[i%2]%2)a[i%2]--;
        a[(i+1)%2] += a[i%2]/2;
        a[i%2] /= 2;
    }
    
    cout << a[0]<<" "<<a[1]<<endl;
    
    return 0;
}