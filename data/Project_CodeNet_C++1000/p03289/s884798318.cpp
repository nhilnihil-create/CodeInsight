/*  
    Through the fish-eyed lens of tear stained eyes
    I can barely define the shape of this moment in time
    And far from flying high in clear blue skies
    I'm spiralling down to the hole in the ground where I hide
    _________________________
    _________________________
    1032 Hours of Solitude
    Quarantine_Day : 43
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int       ll;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef pair<int, int>      pii;
typedef pair<ll, ll>		pll;

#define pb(n)           push_back(n)
#define GSORT(v)        sort(v.begin(), v.end(), greater<ll>())
#define SORT(v)         sort(v.begin(), v.end());
#define REV(v)          reverse(v.begin(), v.end());
#define db(a)           cout<<#a<<" = "<<a<<endl;
#define FIN             freopen("in.txt","r",stdin);
#define FOUT            freopen("out.txt","w",stdout);
#define REP(i,n)        for(int i = (int)(0); i < (int)(n); i++)
#define FOR(i, a, b)    for(int i = (int)a; i <= (int)b; i++)    

#define MAX 1000

bool go(string s){
    if(s[0] != 'A') return false;
    if(count(s.begin() + 2, s.end() - 1, 'C') != 1) return false;
    for(auto c : s){
        if(c != 'A' && c != 'C' && isupper(c)) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin>>s;
    cout<<(go(s)?"AC\n":"WA\n");

    return 0;
}
