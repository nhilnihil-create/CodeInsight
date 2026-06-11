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
#include <map>
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

int main(){
    LL n;
    string s;
    map<string, LL> st;
    LL m;
    string t;
    cin >> n;
    for(LL i=0; i<n; i++){
        cin >> s;
        st[s]++;
    }
    cin >> m;
    for(LL i=0; i<m; i++){
        cin >> t;
        st[t]--;
    }
    LL kiyu=0;
    for(auto itr=st.begin(); itr!=st.end(); itr++){
        kiyu=max(kiyu, itr->second);
    }

    cout << kiyu << endl;

    return 0;
}
