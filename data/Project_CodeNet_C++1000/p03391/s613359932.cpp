#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n),b(n);

    long long sum=0;
    int mn=INT_MAX;
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        if(a[i]>b[i]){
            mn=min(mn,b[i]);
        }
        sum+=a[i];
    }
    if(mn<INT_MAX){
        cout << sum-mn << endl;
    }
    else{
        cout << 0 << endl;
    }

    return 0;
}
