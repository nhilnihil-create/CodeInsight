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


int main() {
    int N, Z, W;
    cin>>N>>Z>>W;
    int a, b = 0;
    for (int i=0; i<N; i++) {
        a = b;
        cin>>b;
    }
    long long ans = abs(0LL + W - b);
    if (N > 1) ans = max(ans, abs(0LL + a - b));
    cout<<ans<<endl;
}
