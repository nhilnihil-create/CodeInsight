#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

signed main() {
    int n;
    int d,x;
    int a[101];
    int sum = 0;
    int j = 1;
    cin >> n >> d >> x;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i ++){
        sum ++;
        j = 1;
        while(j*a[i]+1 <= d){
            sum++;
            j ++;
        }
    }

    cout <<sum+x;

    return 0;
}