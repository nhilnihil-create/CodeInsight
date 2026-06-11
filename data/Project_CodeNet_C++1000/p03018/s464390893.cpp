#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

signed main(){

    string s;
    cin>>s;
    s.push_back('F');
    s.push_back('F');
    s.push_back('F');

    lli ans=0;

    lli aCnt=0;
    lli bcCnt=0;
    lli state=0;
    REP(i,0,s.size()-2){
        if(state==0){
            if(s.at(i)=='A')aCnt++;
            else{
                i--;
                state=1;
                continue;
            }
        }
        else{
            if(s.at(i)=='A'){
                state=0;
                ans += (aCnt*bcCnt);
                bcCnt=0;
                i--;
            }
            else if(s.at(i)=='B' && s.at(i+1)=='C'){
                bcCnt++;
                i++;
            }
            else{
                ans += (aCnt*bcCnt);
                aCnt=0;
                bcCnt=0;
                state=0;
            }
        }
    }
    cout<<ans<<endl;

	return 0;
}