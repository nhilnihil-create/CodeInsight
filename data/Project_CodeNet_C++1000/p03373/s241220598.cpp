#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)


int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans=1e7;
    int min=a*x+b*y;
    for(int i=0; i <= max(x,y); i++){
        ll apizza = max(0, x-i);
        ll bpizza = max(0, y-i);
        ans = i*2*c+apizza*a+bpizza*b;
        if(min > ans) min = ans;
    }
    cout <<  min << endl;
}