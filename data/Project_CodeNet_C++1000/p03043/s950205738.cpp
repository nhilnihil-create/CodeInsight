#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define itn int

int main(void){
    int n,k;
    cin >> n >> k;
    
    long double ans = 0;
    for(int i = 1;i <= n;i++){
        int alina = i;
        long double cnt = 1;
        while( 1 ){
            if(alina >= k)break;
            alina *= 2;
            cnt /= 2;
        }
        ans += cnt;
    }
    cout << setprecision(20) << ans / n << endl;
}