#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    double y = n;
    double a[n];
    double sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        sum += a[i];
    }

    sum = sum/y;

    int ans = 0;
    double x = abs(sum-a[0]);

    for(int i=1;i<n;i++){
        if(x>abs(sum-a[i])){
            ans = i;
            x = abs(sum-a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}