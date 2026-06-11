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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    ll cnt=0;
    bool frg = true; // all odd number
    for(int i=0;i<N;i++){
        if(A[i]%2==0){
            frg = false;
            break;
        }
    }
    // all odd number
    ll cnt1=1;
    if(frg){
        for(int i=0;i<N;i++){
            cnt1*=3;
        }
        cnt = cnt1-1;
    }
    //
    else{
        ll exclude =1;
        for(int i=0;i<N;i++){
            if(A[i]%2==0){
                exclude*=2;
            }
        }
        ll cnt2=1;
        for(int i=0;i<N;i++){
            cnt2*=3;
        }
        cnt = cnt2 - exclude;
    }
    cout << cnt << endl;
}