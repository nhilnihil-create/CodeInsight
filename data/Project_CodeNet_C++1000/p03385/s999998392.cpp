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
#include <iomanip>
#include <unordered_map>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
typedef long double ld;
const char sp = ' ';

using namespace boost::multiprecision;
using namespace std;

int main(void){
    ll a=0, b=0, c=0;
    string S;
    cin>>S;
    rep(i, S.size()){
        if(S[i]=='a') a++;
        if(S[i]=='b') b++;
        if(S[i]=='c') c++;
    }
    if(a==1 && b==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
