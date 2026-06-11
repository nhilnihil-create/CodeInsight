#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!


void solve(){
    char s[5];
    scanf ("%s",&s);
    int a=s[0]-'0',b=s[1]-'0',c=s[2]-'0',d=s[3]-'0';
    if(a-b-c-d==7) printf ("%d-%d-%d-%d=7\n",a,b,c,d);
    else if(a-b-c+d==7) printf ("%d-%d-%d+%d=7\n ",a,b,c,d);
    else if(a-b+c-d==7) printf ("%d-%d+%d-%d=7\n",a,b,c,d);
    else if(a-b+c+d==7) printf ("%d-%d+%d+%d=7\n",a,b,c,d);
    else if(a+b-c-d==7) printf ("%d+%d-%d-%d=7\n",a,b,c,d);
    else if(a+b-c+d==7) printf ("%d+%d-%d+%d=7\n",a,b,c,d);
    else if(a+b+c-d==7) printf ("%d+%d+%d-%d=7\n",a,b,c,d);
    else if(a+b+c+d==7) printf ("%d+%d+%d+%d=7\n",a,b,c,d);}

int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}