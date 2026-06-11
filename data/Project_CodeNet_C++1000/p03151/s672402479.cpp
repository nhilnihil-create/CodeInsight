#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    long long sum = 0,sum1 = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        sum += a[i] - b[i];
        if(a[i] < b[i]){
            sum1 += b[i] - a[i];
            cnt++;
        }
    }

    int c[n];
    for(int i = 0; i < n; i++){
        c[i] = a[i] - b[i];
    }
    sort(c,c+n);
    reverse(c,c+n);
    for(int i = 0; i < n; i++){
        if(c[i] > 0 && sum1 > 0){
            sum1 -= c[i];
            cnt++;
        }
    }
    if(sum < 0 || sum1 > 0){
        cout << -1 << endl;
    }else{
        cout << cnt << endl;
    }
    return 0;
}

