#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define rep(i,n) (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int a,b,i;
    cin >> a >> b;
    int ans,sa,sum=0;
    
    sa = b - a;
    
    for(i = 0; i <= sa; i++) sum += i;
    ans = sum-b;
    
    cout << ans << endl;
    return 0;
}
