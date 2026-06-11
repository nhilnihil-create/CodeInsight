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

    lli n;
    cin>>n;

    lli num=0;
    cout<<num<<endl;

    string s;
    cin>>s;

    lli start;
    if(s=="Male")start=0;
    else if(s=="Female")start=1;
    else{
        cout<<endl;
        return 0;
    }

    lli small=0,large=n;
    while(1){
        lli middle = (small+large)/2;
        cout<<middle<<endl;

        string q;
        cin>>q;
        lli now;
        lli hope = (start+middle)%2;
        if(q=="Male")now=0;
        else if(q=="Female")now=1;
        else{
            cout<<endl;
            return 0;
        }

        if(hope == now)small=middle+1;
        else large = middle-1;
    }


	return 0;
}