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
//#define MAX 100100
//#define NIL -1
//#define INFTY 1000000000000000000

/*
bool cmp(const pair<LL,LL> &x, const pair<LL,LL> &y)
{
    return x.first < y.first;
}
*/

int main(){
    LL n;
    LL m;
    cin >> n >> m;
    vector<pair<LL,LL>> ab(m);
    vector<pair<LL,LL>> cut;

    for(LL i=0; i<m; i++){
        cin >> ab[i].first >> ab[i].second;
        ab[i].first--;
        ab[i].second--;
    }
    sort(ab.begin(), ab.end());
    for(LL i=0; i<m; i++){
        if(cut.size()==0){
            cut.push_back(make_pair(ab[i].first, ab[i].second));
        }else if(ab[i].first<cut[cut.size()-1].second){
            cut[cut.size()-1].first=max(cut[cut.size()-1].first, ab[i].first);
            cut[cut.size()-1].second=min(cut[cut.size()-1].second, ab[i].second);
        }else{
            cut.push_back(make_pair(ab[i].first, ab[i].second));
        }
    }

    cout << cut.size() << endl;

    return 0;
}
