#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define bg(a) a.begin()
#define en(a) a.end()
#define all(a) bg(a), en(a)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(void){
    vi a(3);
    rep(i,3)cin>>a[i];
    sort(all(a));
    
    cout << a[2]-a[0] << endl;
    
    return 0;
}