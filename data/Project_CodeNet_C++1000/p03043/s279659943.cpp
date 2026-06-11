#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n,k;
    cin >> n >> k;
    long double win=n;
    long double sum=0;
    long double num;
    win=1/win;

    for(int i=1; i<=n; i++){
        num=1.0;
        while(i*num<k){
            num*=2.0;
        }
        sum+=win/num;
        //cout << sum << endl;
    }
    cout << fixed << setprecision(15) << sum << endl;
}