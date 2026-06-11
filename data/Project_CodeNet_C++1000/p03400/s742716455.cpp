#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n, d, x;
    cin >> n ;
    cin >> d >> x;
    int a[n];
    rep(i, n) cin >> a[i];

    int res = 0, date = 1;
    for(int i=0; i<n; i++){
        res++; // 一日目
        date = 1;
        while(true){
            date += a[i];
            if(date <=d){
                res++;
            }else if(date > d){
                break;
            }
        }
    }
    cout << (res + x) << endl;
    return 0;
}