#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

const long INF = 10000000000000;
 
int main(){
    int A, B, Q;
    cin >> A >> B >> Q;
 
    vector<long> s, t;
    s.push_back(-1*INF);
    t.push_back(-1*INF);
    for(int i=0; i<A; i++){
        long a;
        cin >> a;
        s.push_back(a);
    }
    for(int i=0; i<B; i++){
        long b;
        cin >> b;
        t.push_back(b);
    }
    s.push_back(INF);
    t.push_back(INF);
 
    long x[Q];
    for(int i=0; i<Q; i++){
        cin >> x[i];
    }
 
    long ans[Q];
    for(int i=0; i<Q; i++){
        ans[i] = 100000000000000;
 
        auto sind = lower_bound(s.begin(), s.end(), x[i]);
        auto tind = sind;
        vector<long> sl;
        sl.push_back(*sind);
        sl.push_back(*(--sind));
        for(auto se : sl){
            tind = lower_bound(t.begin(), t.end(), se);
            ans[i] = min(ans[i], abs(x[i]-se)+abs(se-(*tind)));
            tind--;
            ans[i] = min(ans[i], abs(x[i]-se)+abs(se-(*tind)));
        }
 
        tind = lower_bound(t.begin(), t.end(), x[i]);
        vector<long> tl;
        tl.push_back(*tind);
        tl.push_back(*(--tind));
        for(auto te : tl){
            sind = lower_bound(s.begin(), s.end(), te);
            ans[i] = min(ans[i], abs(x[i]-te)+abs(te-(*sind)));
            sind--;
            ans[i] = min(ans[i], abs(x[i]-te)+abs(te-(*sind)));
        }
    }
 
    for(int i=0; i<Q; i++){
        cout << ans[i] << endl;
    }
 
    return 0;
}
