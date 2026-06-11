#include <iostream>
#include <vector>
using namespace std;
#define INF 10000000001
vector<long long> s,t;

pair<int, int> binary_search(long long x, char c){
    if(c == 's'){
        int first = 0;
        int last = s.size();
        while(last - first > 1){
            int middle = (last+first)/2;
            if(s[middle] <= x) first = middle;
            else last = middle;
        }
        if(s[first] == 0) first = last = 1;
        if(s[last] == INF) last = first = s.size() - 2;
        return make_pair(first,last);
    }
    else if(c == 't'){
        int first = 0;
        int last = t.size();
        while(last - first > 1){
            int middle = (last+first)/2;
            if(t[middle] <= x) first = middle;
            else last = middle;
        }
        if(t[first] == 0) first = last = 1;
        if(t[last] == INF) last = first = t.size() - 2;
        return make_pair(first,last);
    }
}
long long calc(long long x, pair<int,int> a, pair<int,int> b){
    long long s1 = s[a.first], s2 = s[a.second], t1 = t[b.first], t2 = t[b.second];
    long long tmp = 0, ans = 100000000000;
    pair<int,int> p = binary_search(s1, 't');
    tmp = abs(x-s1) + min(abs(s1-t[p.first]), abs(s1-t[p.second]));
    ans = min(ans, tmp);
    p = binary_search(s2,'t');
    tmp = abs(x-s2) + min(abs(s2-t[p.first]), abs(s2-t[p.second]));
    ans = min(ans, tmp);
    p = binary_search(t1,'s');
    tmp = abs(x-t1) + min(abs(t1-s[p.first]), abs(t1-s[p.second]));
    ans = min(ans, tmp);
    p = binary_search(t2,'s');
    tmp = abs(x-t2) + min(abs(t2-s[p.first]), abs(t2-s[p.second]));
    ans = min(ans, tmp);
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,q;
    cin >> a >> b >> q;
    s.push_back(0), t.push_back(0);
    for(int i = 0;i < a; i++){
        long long x; cin >> x;
        s.push_back(x);
    }
    s.push_back(INF);
    for(int i = 0; i < b; ++i){
        long long x; cin >> x;
        t.push_back(x);
    }
    t.push_back(INF);
    for(int i = 0;i < q; ++i){
        long long x; cin >> x;
        pair<int, int> ps = binary_search(x, 's');
        pair<int, int> pt = binary_search(x, 't');
        cout << calc(x,ps,pt) << endl;
    }
    return 0;
}