#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        double x;
        string u;
        cin >> x >> u;
        if(u=="BTC")
        {
            ans += (x * 380000);
        }
        else
        {
            ans += (x);
        }
    }
    cout << ans << endl;
    return 0;
}