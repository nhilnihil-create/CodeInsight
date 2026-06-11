#include <bits/stdc++.h>
using namespace std;
int main(){     
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        s += a[i];
    }


    int ans = 0;
    int mindiff = 100000000;
    for(int i = 0;i<n;i++){
        if (abs(s-n*a[i]) < mindiff){
            mindiff = abs(s-n*a[i]);
            ans = i;
        }
    }
    cout << ans << endl;
}


