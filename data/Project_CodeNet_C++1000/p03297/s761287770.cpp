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
            LL t;
            if(c-b-a%g<0){
                t=(c-b-a%g)/g;
                if(abs(c-b-a%g)%g==0) t++;
            }
            else{
                t=(c-b-a%g)/g+1; 
            }
            if(a%g+g*t>=0) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
