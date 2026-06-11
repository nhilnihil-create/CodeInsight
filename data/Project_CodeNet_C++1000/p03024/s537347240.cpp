#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <math.h>
#include <iomanip>

typedef long long ll;
using namespace std;
int main(){
    string s;
    cin >> s;
    int ctr=0;
    for(auto ss : s){
        ctr += (ss=='o');
    }
    ctr += (15 - s.size());
    string ret[] = {"NO", "YES"};
    cout << ret[(ctr>=8)] << endl;
    return 0;
}


