#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int maxDiff = -1;
    int ans = -1;
    int large = a[n - 1];
    for(int i = 0; i <= n - 2; i++){
        int temp = a[i];
        int tempDiff = min(temp, large - temp);

        if(tempDiff > maxDiff){
            maxDiff = tempDiff;
            ans = temp;
        }
    }

    cout << large << " " << ans << endl;

    return 0;
}