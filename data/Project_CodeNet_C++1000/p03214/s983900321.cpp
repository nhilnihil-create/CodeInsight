#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[102];
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    int d = 10000000;
    int ans = -1;
    for(int i = 0; i < n; i++){
        if(abs(s - a[i] * n) < d){
            d = abs(s - a[i] * n);
            ans = i;
        }
    }
    cout << ans << endl;
}