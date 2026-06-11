#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
bool isPerfectNum(int num)
{
    for (int i = 2; i <= 40; i++)
    {
        int temp=num;
        int cnt = 0;
        while (temp != 1)
        {
            if (temp % i == 0)
            {
                temp /= i;
                cnt++;
            }
            else
            {
                cnt = 0;
                break;
            }
        }
        if (cnt >= 2)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    //freopen("B.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    scanf("%d", &x);
    if(x==1){
        printf("%d",1);
    }
    for(int i = x;i>=2;i--){
        if(isPerfectNum(i)){
            printf("%d",i);
            return 0;
        }
    }
    return 0;
}