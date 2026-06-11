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
    int A,B,C;
    vector<int> num(3);
    for(int i=0;i<3;i++){
        cin >> num[i];
    }
    sort(num.begin(),num.end());
    A = num[0];
    B = num[1];
    C = num[2];
    int diff2 = num[2] - num[1];
    int diff1 = num[1] - num[0];
    int cnt=0;
    if(diff1%2==0){
        cnt+= diff1/2;
    }
    else{
        cnt++;
        cnt+= diff1/2;
        diff2++;
    }
    cnt+=diff2;
    cout << cnt << endl;
}