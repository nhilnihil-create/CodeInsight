#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <set>
#include <algorithm> // sort

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;



int main(){
    int n;
    cin >> n;
    vector <int> p(n);
    vector <int> kai(n);
    //階段になっている数列(1,2,3,4)の最長な気がする
    //操作が「階段以外一気に取り出して、順番に入れ替える」と同義っぽい
    // kai[i] = iがなんばんめに登場するか
    REP(i,n)
    {
        cin >> p[i];
        --p[i];
        kai[p[i]] = i;
    }

    int ren_m = 0;
    int ren = 1;
    for(int i = 0; i < n-1; ++i)
    {
        if(kai[i] < kai[i+1])
        {
            ++ren;
        }
        else
        {
            ren_m = max(ren_m, ren);
            ren = 1;
        }
    }

    ren_m = max(ren_m, ren);

    int res;
    res = n - ren_m;
    cout << res << endl;

    return 0;
}
