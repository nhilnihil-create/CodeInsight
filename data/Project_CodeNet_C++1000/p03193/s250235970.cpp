//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define REP(i,n)  for(int i=0;i<(n);i++)

int main() {
    int n,ans=0;
    cin>>n;
    LL h,w; cin>>h >>w;
    vector<vector<long long>> ab(n,vector<long long>(2));
    for(int i=0;i<n;i++){
        cin>>ab[i][0] >>ab[i][1];
        if(ab[i][0]>=h&&ab[i][1]>=w)ans++;
    }
    cout<<ans<<endl;
    return 0;
}