#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

int main() {
    

    string s;
    cin >> s;
    ll cnt = 0;
    for (ll i=0;i<s.length();i++){
        if(s[i] == 'o'){
            cnt++;
        }
    }
    if(cnt + (15 - s.length()) >= 8){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}