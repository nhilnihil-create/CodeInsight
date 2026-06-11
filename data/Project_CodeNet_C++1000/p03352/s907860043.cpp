#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <numeric>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>
#include <set>
using ll =long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;


int main() {
    ll X;
    cin >> X;
    int ma = 1;
    int p;
    for(int i=2; i<=X; i++){
        p = 2;
        while(1){
            if(pow(i, p) > X){
                break;
            }
            ma = max(ma, (int)pow(i, p));
            p++;
        }
    }
    cout << ma << endl;
}