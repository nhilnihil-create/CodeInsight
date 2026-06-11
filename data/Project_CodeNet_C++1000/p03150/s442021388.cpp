#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define COIN const int
#define ite iterator
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REPD(i,n) for((i)=(n)-1;(i)>=0;(i)--)

#define ALL(c) (c).begin(), (c).end()
#define sz(s) (s).size()
#define CLEAR(x) memset(x,0,sizeof x);

#define MP make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define X first
#define Y second

#define VI vector<int>
#define VS vector<string>
#define VII vector<PII>
#define VVI vector<VI>

#define PIII 3.1415926
#define PI 3.14
/*****************************************************************************/

using namespace std;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    string s; cin >> s;
    int i,j;
    const string k="keyence";
    for (i=0;i<=k.size();i++) {
        bool f=1;
        for (j=0;j<i;j++) {
            if (s[j]!=k[j]) {
                f=0;
                break;
            }
        }
        if (!f) {
            continue;
        }
        for (j=0;j<k.size()-i;j++) {
            if (s[s.size()-1-j]!=k[k.size()-1-j]) {
                f=0;
                break;
            }
        }
        if (f) {
            cout <<"YES" <<endl;
            return 0;
        }
    }
    cout <<"NO" <<endl;
    return 0;
}
/******************************************************************************
******************************************************************************/
