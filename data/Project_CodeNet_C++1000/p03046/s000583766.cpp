#include <bits/stdc++.h>

using namespace std;

#define li long long int
#define FOR(i,l,r) for( li i = l-(l>r); i != r-(l>r); i += 1-2*(l>r) )

int main() {
    li m,k; cin>>m>>k;
    li u = (1ll<<m)-1;
    if( k > u || ( k == 1 && m <= 1 ) ) {
        cout<<"-1\n";
        return 0;
    }
    if( k == 0 ) {
        FOR(i,0,u+1) cout<<i<<" "<<i<<" ";
        cout<<"\n";
        return 0;
    }
    int a = 1;
    if( k == 1 ) a++;
    cout<<0<<" "<<k<<" "<<0<<" "<<a<<" "<<(k^a);
    deque<li> q;
    q.push_back(k);
    FOR(i,0,u+1) {
        if( i != k && i != 0 && i != a && i != (k^a) ) {
            q.push_back(i);
            q.push_front(i);
        }
    }
    while( !q.empty() ) {
        cout<<" "<<q.front();
        q.pop_front();
    }
    cout<<" "<<(k^a)<<" "<<a<<"\n";
    return 0;
}