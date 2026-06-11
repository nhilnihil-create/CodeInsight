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

using namespace std;


int main() {
    string s;
    cin>>s;
    int n = s.length();
    vector<int> f(n, 0);
    map<int, int> m;
    int a = 0;
    m[0] = 0;
    for (int i=0; i<s.length(); i++) {
        int offset = s[i] - 'a';
        if (a & (1<<offset)) a &= ~(1<<offset);
        else a |= (1<<offset);
        int min_cut = INT_MAX;
        for (int j=0; j<26; j++) {
            int p_a = a ^ (1<<j);
            if (m.find(p_a) != m.end() && m[p_a] < min_cut) min_cut = m[p_a];
        }
        if (m.find(a) != m.end() && m[a] < min_cut) min_cut = m[a];
        f[i] = 1 + min_cut;
        if (m.find(a) == m.end() || m[a] > 1 + min_cut) m[a] = 1 + min_cut;
    }
    cout<<f[n-1]<<endl;
}