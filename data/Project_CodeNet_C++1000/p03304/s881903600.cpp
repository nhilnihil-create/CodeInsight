#include <bits/stdc++.h>
using namespace std;

int main(){
    double n,m,d;
    cin >> n >> m >> d;
    double ans;
    if(d==0){
        ans=n/(n*n)*(m-1);
    }
    else{
        ans=(2*(n-d))/(n*n)*(m-1);
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}
