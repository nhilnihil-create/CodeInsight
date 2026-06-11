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
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int x;
    cin >> x;
    int max= 0;
    int num;
    for(int i=1;i<=x;i++){
        num = i;
        for(int j=1;j<=x;j++){
            num*=i;
            if(num > x){
                break;
            }
            else{
                if(max < num){
                max = num;
            }
            }
            
        }
    }
    cout << max << endl;
}