#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define inf 1000000000
#define ninf -1000000000
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector< pair<int,int> > vii;
typedef long long ll;
 
#define  modu 1000000007

int main() {
   
    {
        ll n,p,i;
        cin>>n>>p;
        for(i= pow(p,(1.0/n))+1;i>=1;i--)
            if(p%(ll)pow(i,n)==0)
            {
                cout<<i;
                break;
            }
    }
    return 0;
}