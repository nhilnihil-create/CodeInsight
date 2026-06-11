#include <iostream>
#include <algorithm>

using namespace std;

long min_dist(long * s, long * t, long x, int A, int B){
    long s2 = *lower_bound(s, s + A, x);
    long s1 = *(lower_bound(s, s + A, x) - 1);
    long t2 = *lower_bound(t, t + B, x);
    long t1 = *(lower_bound(t, t + B, x) - 1);
    long ans = min(max(s2, t2) - x, x - min(s1, t1));
    ans = min(ans, min(min(2 * s2 - t1 - x, 2 * t2 - s1 - x), min(s2 - 2 * t1 + x, t2 - 2 * s1 + x)));
    return ans;
}



int main(){
    int A, B, Q;
    cin >> A >> B >> Q;
    long s[A+2], t[B+2], x[Q+2];
    s[0] = -long(1e10)-1;
    t[0] = -long(1e10)-1;
    x[0] = -long(1e10)-1; 
    for(int i=0; i<A; i++) cin >> s[i+1];
    for(int i=0; i<B; i++) cin >> t[i+1];
    for(int i=0; i<Q; i++) cin >> x[i+1];
    s[A+1] = long(2e10)+1;
    t[B+1] = long(2e10)+1;
    x[Q+1] = long(2e10)+1; 



    for(int i=0; i<Q; i++){
        long ans = min_dist(s, t, x[i+1], A+2, B+2);
        cout << ans << endl;
    }
    return 0;
}