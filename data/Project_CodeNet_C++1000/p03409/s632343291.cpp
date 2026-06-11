#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 10000100
//#define NIL -1

bool cmp_f(const pair<LL, LL> &x, const pair<LL, LL> &y)
{
    return x.first < y.first;
}

bool cmp_s(const pair<LL, LL> &x, const pair<LL, LL> &y)
{
    return x.second > y.second;
}

int main() {
    LL n;
    LL a;
    LL b;
    LL c;
    LL d;
    LL ans=0;
    cin >> n;
    vector<pair<LL, LL>> ab(n);
    vector<pair<LL, LL>> cd(n);
    vector<bool> ab_end(n, false);
    for(LL i=0; i<n; i++){
        cin >> a >> b;
        ab[i]=make_pair(a, b);
    }

    sort(ab.begin(), ab.end(), cmp_s);

    for(LL i=0; i<n; i++){
        cin >> c >> d;
        cd[i]=make_pair(c, d);
    }

    sort(cd.begin(), cd.end(), cmp_f);

    for(LL i=0; i<n; i++){
        for(LL j=0; j<n; j++){
            if(ab_end[j]==false){
                if(ab[j].first<cd[i].first && ab[j].second < cd[i].second){
                    ans++;
                    ab_end[j]=true;
                    break;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
