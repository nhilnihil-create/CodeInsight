#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)

#define INF 100000000



int main(){
    int a,b,k;
    cin>>a>>b>>k;

    set<int> set;

    int bound1 = min(a+k,b+1);
    for(int i=a; i<bound1; ++i) set.insert(i);

    int bound2 = max(a-1,b-k);
    for(int i=b; i>bound2; --i) set.insert(i);

    auto itr = set.begin();
    while(itr != set.end()){
        cout<< *itr <<endl;
        ++itr;
    }
    return 0;
}