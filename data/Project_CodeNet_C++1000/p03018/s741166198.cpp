#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
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
    ll n = s.length();
    char state = 'X';
    ll memo = 0;
    ll ans = 0;
    for(ll i=n-1;i>=0;i--){
//        cout << "No. " << i+1 << " state: " << state << " memo: " << memo << " score: " << ans << endl;
        if(state == 'X'){
            if(s[i] == 'A'){
                continue;
            }
            else if(s[i] == 'B'){
                state = 'B';
            }else{
                state = 'C';
            }
        }else if(state == 'B'){
            if(s[i] == 'A'){
                ans += memo;
                state = 'B';
            }
            else if(s[i] == 'B'){
                memo = 0;
                state = 'B';
            }else{
                state = 'C';
            }
        }else{
            if(s[i] == 'A'){
                memo = 0;
                state = 'X';
            }
            else if(s[i] == 'B'){
                memo++;
                state = 'B';
            }else{
                memo = 0;
                state = 'C';
            }
        }
    }
    cout << ans << endl;
}