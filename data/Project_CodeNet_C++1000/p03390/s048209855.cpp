#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

bool C(long long A, long long B, long long x){
    long long mx = 0;
    long long mid = x / 2;
    for(long long y=mid-100; y<=mid+100; y++){
        if(y<1 || y>x) continue;
        long long a = y;
        long long b = x-y+1;
        if(a >= A) a++;
        if(b >= B) b++;
        mx = max(mx, a*b);
    }
    return mx < A*B;
}

long long solve(long long A, long long B){
    long long ub = A + B;
    long long lb = 0;
    while(ub - lb > 1){
        long long mid = (ub-lb)/2+lb;
        if(C(A, B, mid)) lb = mid;
        else ub = mid;
    }
    return lb;
}

int main(){
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        long long A, B;
        cin >> A >> B;
        cout << solve(A, B) << endl;
    }

    return 0;
}