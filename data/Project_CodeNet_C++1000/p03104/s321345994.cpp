#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <tuple>
#include <climits>
#include <unordered_map>

using namespace std;

long long f(long long a) {
    if (a <= 0) return 0;
    long long ans = 0;
    for (int i=40; i>0; i--) {
        if (a & (1LL<<i) && !(a & 1)) ans |= (1LL<<i);
    }
    ans |= (a&1)^(a>>1&1);
    return ans;
}
int main() {
    long long a, b;
    cin>>a>>b;
    cout<<(f(a-1)^f(b))<<endl;
}

