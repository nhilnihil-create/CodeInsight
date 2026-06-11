#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=998244353;
const LL LINF=1LL<<62;
const LL INF=1<<17;


int main(){
    int T;
    cin >> T;
    while(T--){
        LL a,b,c,d;
        cin >> a >> b >> c >> d;
        if(b>a) puts("No");
        else if(b>d) puts("No");
        else if(c>=b) puts("Yes");
        else{
            LL g=__gcd(b,d);
            if(c%b<b-g+a%g) puts("No");
            else puts("Yes");
       }
    }
    return 0;
}
