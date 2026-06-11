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
#include <limits>
#include <iomanip>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    string S;
    cin >> S;
    vector<char> vec(S.size());
    for(int i=0;i<S.size();i++){
        vec[i]=S[i];
    }
    int cnt=0;
    for(int i=1;i<S.size();i++){
        if( (vec[i-1-cnt]=='0'&&vec[i-cnt]=='1')||(vec[i-1-cnt]=='1'&&vec[i-cnt]=='0')){
            vec.erase(vec.begin() +(i-cnt));
            vec.erase(vec.begin() +(i-1-cnt));
            cnt+=2;
        }
    }
    cout << cnt << endl;
}