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
    int N,D,X;
    cin >> N >> D >> X;
    vector<int> consume(N);
    for(int i=0;i<N;i++){
        int a;
        int cnt = 1;
        cin >> a;
        for(int j=1;j>0;j++){
            if( (j*a+1) <= D){
                cnt++;
            }
            else{
                consume[i]=cnt;
                break;
            }
        }
    }
    ll total=0;
    for(int i=0;i<N;i++){
        total = total + consume[i];
    }
    ll ans = total + X;
    cout << ans << endl;
}
