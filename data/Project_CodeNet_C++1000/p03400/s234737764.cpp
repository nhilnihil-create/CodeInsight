#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;


int main(){
    int n, d, x;
    cin >> n >> d >> x;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        for(int j = 0; ; j++){
            if(j*a+1 <= d){
                cnt++;
            }else{
                break;
            }
        }
    }
    cout << x + cnt << endl;

}
