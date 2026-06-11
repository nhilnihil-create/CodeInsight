#include <iostream>
#include <string>
using namespace std;
int main(){
    int n; cin >> n;
    double ans = 0;
    for(int i = 0; i < n; i++){
        double x;
        string u;
        cin >> x >> u;
        if(u == "BTC") ans += 380000*x;
        else ans += x;
    }
    printf("%.10f\n", ans);
    return 0;
}