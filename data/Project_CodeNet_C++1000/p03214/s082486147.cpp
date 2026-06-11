#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    double ave = 0;
    cin >> n;
    vector<int> a(n);
    vector<double> b(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        ave += a[i];
    }
    double min = ave;int ans = 0;
    ave /= n;
    for(int i = 0;i < n;i++){
        b[i] = fabs(a[i] - ave);
        if(b[i] < min){
            min = b[i];
            ans = i;
        }
    }
    cout << ans ;
}