#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    ll X;
    cin>>X;
    ll Maxim=0;
    rep1(b, 1000) reps(p, 2, 11){
        if(pow(b, p)<=X) Maxim=max(Maxim, (ll)pow(b, p));
    }
    cout<<Maxim<<endl;
    return 0;
}
