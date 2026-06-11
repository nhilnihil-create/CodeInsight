#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)



int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    ll res = 0;
    int left = 0;
    int right = 0;
    int sum = 0;
    for (left = 0;left < n;left++){
        while(right < n && (sum ^ v[right]) == (sum + v[right])){
            sum += v[right];
            right++;
        }
        res += right-left;
        if (left == right) right++;
        else {
            sum -= v[left];
        }
    }
    
    cout << res << endl;

    return 0;

}
