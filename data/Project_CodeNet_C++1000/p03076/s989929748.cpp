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
    int A,B,C,D,E;
    cin >> A >> B >> C >> D >> E  ;
    vector<int> time = {A,B,C,D,E};
    int a,b,c,d,e;
    a = A % 10;
    b = B % 10;
    c = C % 10;
    d = D % 10;
    e = E % 10;
    vector<int> add = {a,b,c,d,e};
    sort(add.begin(),add.end());
    int first;
    bool frg= false;
    for(int i=0;i<5;i++){
        if(add[i]!=0){
            first =add[i];
            frg = true;
            break;
        }
    }
    int ans = 0;
    for(int i=0;i<5;i++){
        if(time[i]%10==0){
            ans = ans + time[i];
        }
        else{
            ans = ans + ((time[i]/10)+1)*10 ;
        }
    }
    if(frg){
        ans = ans - 10 + first;
    }
    cout << ans << endl;
}