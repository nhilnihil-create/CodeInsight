#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iomanip>
#include <limits.h>

using namespace std;    
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const bool DEBAG = false;

int main(){

    vector<int> a(3);
    vector<int> b(3);

    for(int i = 0; i < 3; i++) cin >> a[i];
    for(int i = 0; i < 3; i++) cin >> b[i];

    vector<int> cnt(4);
    for(int i = 0; i < 3; i++){
        cnt[ a[i]-1 ] ++;
        cnt[ b[i]-1 ] ++;
    }

    sort(all(cnt));
    if(cnt[3] > 2){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }


}