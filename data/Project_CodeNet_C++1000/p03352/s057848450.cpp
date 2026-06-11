#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    int x;
    cin >> x;
    int res = 0;
    for (int i = 1; i < 1000; i++)
    {
        for (int j = 2; j < 1000; j++)
        {
            ll tmp = pow(i,j);
            if(tmp>x){
                continue;
            }
            if(res < tmp){
                res = tmp;
            }
        }
        
    }
    cout << res << endl;
    
}
