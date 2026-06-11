#include <bits/stdc++.h>

using namespace std;

int main(){
    long double n,m,d,now;
    cin >> n >> m >> d;
    if(d==0){
        cout << setprecision(20) << (m-1)/n << endl;
    }else{
        cout << setprecision(20) << 2*(n-d)*(m-1)/n/n << endl;
    }
}