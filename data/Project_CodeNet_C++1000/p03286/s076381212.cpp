#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

int main()
{
    int N;
    cin >> N;
    string str;
    while(N != 0)
    {
        int r = N % (2);
        if(r < 0) r+= 2;
        N = (N - r) / (-2);
        str += (char)('0' + r);
        
    }
    reverse(str.begin(), str.end());
  if (str == "") str = "0"; 
  cout << str << endl;
}