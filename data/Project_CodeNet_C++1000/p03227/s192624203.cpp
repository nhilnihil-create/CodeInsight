#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
#include <set>
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define P pair<int, int>
 
#define MOD 1000000007
#define INF 2147483647
#define NINF (-2147483647-1)
#define LLINF 9223372036854775807
using ll = long long;
using namespace std; 
 
int main() {
    string S;
    cin >> S;
    if (S.length() == 2) {
        cout << S << endl;
    }
    else {
        cout << S[2] << S[1] << S[0] << endl;
    }
    getchar(); getchar();
    return 0;
}