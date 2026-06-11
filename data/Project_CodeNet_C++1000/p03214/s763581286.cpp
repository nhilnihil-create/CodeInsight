#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    double k = (double)sum / n;
    int ans = 0;
    double dis = 1000.0;
    for(int i = 0; i < n; i++){
        if(dis > abs(k - a[i])){
            dis = abs(k - a[i]);
            ans = i;
        }
    }

    cout << ans << endl;
}