#include <iostream>
//#include <set>
//#include <map>
//#include <iomanip>
#include <algorithm>
//#include <numeric>
//#include <queue>
//#include <stack>
#include <math.h>
#include <vector>
//#include <string>
//#include <list>
//#include <deque>
//#include <unordered_map>
typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 200100
//#define NIL -1

int main() {
    int n;
    vector<LL> a;
    LL tmp_a;
    LL b0;
    LL b1;
    LL b2;
    LL ans0=0;
    LL ans1=0;
    LL ans2=0;
    LL ans;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp_a;
        tmp_a=tmp_a-(i+1);
        a.push_back(tmp_a);
    }
    sort(a.begin(), a.end());
    b0=a[n/2-1];
    b1=(a[n/2-1]+a[n/2])/2;
    b2=a[n/2];
    for(int i=0; i<n; i++){
        ans0+=(LL)abs(a[i]-b0);
        ans1+=(LL)abs(a[i]-b1);
        ans2+=(LL)abs(a[i]-b2);
    }
    if(ans2>ans1){
        if(ans1>ans0){
            ans = ans0;
        }else{
            ans = ans1;
        }
    }else{
        if(ans2>ans0){
            ans = ans0;
        }else{
            ans = ans2;
        }
    }

    cout << ans << endl;

    return 0;
}