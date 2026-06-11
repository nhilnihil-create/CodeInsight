#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long z,w,a[n];
    cin >> z >> w;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    if(n > 2){
        cout << max(abs(a[n-2]-a[n-1]),abs(a[n-1]-w)) << endl;
    }
    else{
        cout << abs(a[n-1]-w) << endl;
    }
    return 0;
}
