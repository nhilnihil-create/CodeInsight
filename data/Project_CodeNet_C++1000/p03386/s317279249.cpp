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
    int A,B,K;
    cin >> A >> B >> K;
    for(int i=0;i<K;i++){
        if(A+i<=B){
            cout << A+i << endl;
        } 
    }
    for(int i=1;i<=K;i++){
        if(A+K<=B-K+i){
            cout << B-K+i << endl;
        }
    }
}