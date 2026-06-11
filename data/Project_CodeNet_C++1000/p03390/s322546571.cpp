#include <bits/stdc++.h> 
 
using namespace std;
 
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
 
 
//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;
 
//container util
//------------------------------------------
#define PB emplace_back
#define MP make_pair 
#define SZ(a) int((a).size())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
//constant
//--------------------------------------------
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

const LL INF=1e9;

int main(){
    int Q;
    cin>>Q;
    vector<LL>res;
    REP(i,Q){
        LL A,B;
        cin>>A>>B;
        if (A>B)swap(A,B);
        if(B-A<=1LL){
            res.PB(2LL*(A-1LL));
        }else{
            LL C=sqrt(A*B);
            if(C*C==A*B)C--;
            if(C*(C+1LL)>=A*B){
                res.PB(2LL*C-2LL);
            }else{
                res.PB(2LL*C-1LL);
            }

        }
    }
    REP(i,Q)cout<<res[i]<<endl;
    return 0;
}