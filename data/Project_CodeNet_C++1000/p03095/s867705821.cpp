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
#define MOD 1000000007

using namespace std;

int main(void){
    ll N;
    string S;
    ll kosu[26];
    cin>>N>>S;
    MEMSET(kosu, 0);
    rep(i, N){
        kosu[S[i]-'a']++;
        kosu[S[i]-'a']%=MOD;
    }
    ll count=1;
    rep(i, 26){
        count*=((kosu[i]+1)%MOD);
        count%=MOD;
    }
    cout<<(count-1+MOD)%MOD<<endl;
    return 0;
}
