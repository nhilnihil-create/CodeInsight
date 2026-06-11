#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    string march = "MARCH";
    string s;
    ll count[5] = {};
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> s;
        for(int j = 0 ; j < 5 ; j++){
            if(march[j] == s[0]){
                count[j]++;
                break;
            }
        }
    }
    long long ans = 0;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = i + 1 ; j < 5 ; j++){
            for(int k = j + 1 ; k < 5 ; k++){
                ans += count[i] * count[j] * count[k];
            }
        }
    }
    cout << ans;
}