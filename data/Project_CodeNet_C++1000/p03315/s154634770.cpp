#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FOR(x,y) for(int i=x; i<y; ++i)
#define FORR(x,y) for(int i=y-1; i>=x; i--)

typedef long long ll;

using namespace std;

int main() {
     string S;
     cin >> S;
    
     int ans = 0;
    
     FOR(0,4){
       S.at(i) == '+' ? ans++ : ans--;
     }
    
     cout << ans << endl;
     return 0;
}
