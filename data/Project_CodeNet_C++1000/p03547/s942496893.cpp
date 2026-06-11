#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define INF 100000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;

int main(){
    string S[2];
    cin >> S[0] >> S[1];
    if(S[0] > S[1]) cout << ">" << endl;
    else if (S[1] > S[0]) cout << "<" << endl;
    else cout << "=" << endl;
    return 0;
}