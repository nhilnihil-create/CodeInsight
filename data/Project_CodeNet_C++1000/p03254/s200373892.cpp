#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits> // FOO_MAX, FOO_MIN
#include <cmath> 
#include <cstdlib> // abs(int), labs(long int), llabs(llint)

#define roundup(n,d) ( ((n) + ((d)-1)) / (d) )
#define ll long long

using namespace std;

int main(void){
    int n,x;
    cin >> n >> x;

    vector<int> a (n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    bool breaked = false;
    int ans = 0;
    for(int i = 0;i < n;i++){
        x -= a[i];
        if(x < 0) {
            ans = i;
            breaked = true;
            break;
        }
    }

    if(!breaked){
        if (x != 0){
            ans = n-1;
        } else {
            ans = n;
        }
    }

    cout << ans << endl;
    return 0;
}