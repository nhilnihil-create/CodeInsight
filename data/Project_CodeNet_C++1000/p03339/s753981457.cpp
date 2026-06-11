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
    string S;
    cin >> N >> S;
    int left,right;
    left = 0,right = 0;
    for(int i = 1; i < N; i++)
    {
        if(S[i] == 'E') right++;
    }
    int ans = right;
    for(int i = 1; i < N; i++)
    {
        if(S[i - 1] == 'W') left++;
        if(S[i] == 'E') right--;
        ans = min(ans,right+left);
    }
    cout << ans << endl;



}