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
    int s;
    cin >> s;
    //
    vector<int> a(1e6+1);
    a[0]=0;
    a[1]=s;
    for(int i=2;i<=1e6;i++){
        if(a[i-1]%2==0){
            a[i]=a[i-1]/2;
        }
        else{
            a[i]= 3*a[i-1] + 1;
        }
    }
    int min_m = 1e6;
    //

    /*
    for(int n=1;n<1e6;n++){
        for(int m=n+1;m<=1e6;m++){
            if(a[n]==a[m]){
                if(min_m > m){
                    min_m =m;
                }
                break;
            }
        }
    }
    */   // m を先に書けばもっと高速化できる
    bool frg = false;
    for(int m=2;m<=1e6;m++){
        for(int n=1;n<m;n++){
            if(a[n]==a[m]){
                min_m=m;
                frg = true;
                break;
            }
        }
        if(frg){
            break;
        }
    }
    cout << min_m << endl;

}
// これだと終わらない、ではどうするか..?