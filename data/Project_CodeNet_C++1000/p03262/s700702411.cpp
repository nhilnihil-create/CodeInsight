#include <iostream>
#include <vector>
using namespace std;
int gcd(int a,int b){
    if(a < b) swap(a,b);
    if(b == 0) return a;
    else return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<int> y(n); for(int i = 0; i < n; ++i) cin >> y[i];
    int gcdx = abs(x-y[0]),gcdy = (n >= 2)?abs(y[0]-y[1]):0;
    for(int i = 0; i < n-1; ++i){
        gcdy = gcd(gcdy, abs(y[i]-y[i+1]));
    }
    for(int i = 0; i < n; ++i){
        gcdx = gcd(gcdx, abs(x - y[i]));
    }
    cout << gcd(gcdx,gcdy) << endl;
    return 0;
}