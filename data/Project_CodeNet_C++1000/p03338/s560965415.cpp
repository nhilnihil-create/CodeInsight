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
    ll N;
    string S;
    ll left[26], right[26];
    cin>>N>>S;
    ll Maxim=0;
    rep(i, N){
        MEMSET(left, 0);
        MEMSET(right, 0);
        rep(j, i+1){
            left[S[j]-'a']++;
        }
        reps(j, i+1, N){
            right[S[j]-'a']++;
        }
        ll count=0;
        rep(j, 26){
            if(left[j]!=0 && right[j]!=0) count++;
        }
        Maxim=max(Maxim, count);
    }
    cout<<Maxim<<endl;
    return 0;
}
