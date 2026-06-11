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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int red = 0;
    int blue = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'R') red ++;
        else blue ++;
    }
    if(red > blue) cout << "Yes" << endl;
    else cout << "No" << endl;
}