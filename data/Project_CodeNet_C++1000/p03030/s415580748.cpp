#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    pair<pair<string,int>,int> p[101];
    for(int i=0;i<N;i++){
        string s;
        int q;
        cin >> s >> q;
        p[i] = make_pair(make_pair(s,-q),i);
    }
    sort(p, p+N);
    for(int i=0;i<N;i++){
        cout<<p[i].second + 1<<endl;
    }
}