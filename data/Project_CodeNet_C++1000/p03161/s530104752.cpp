/*
welcome to my code           hi from    s_agnik1511 
Don't just copy it.
Analyze it.
coz that's what heroes do.....
*/
#include<bits/stdc++.h>
#include<algorithm>
#include<string.h>
#include<numeric>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
#define dude             ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mesc(number,character)   char f[number];memset(f,character,number);
#define mesi(number,value)   int f[number];memset(f,value,number);
#define specio           ifstream cin("input.txt");ofstream cout("output.txt");
#define fr(i,start,end)  for(i=start;i<=end;i++)
#define rf(i,start,end)  for(i=start;i>=end;i--)
#define tst              int t;cin>>t;while(t--)
#define ai               ll n,i;cin>>n;ll a[n];
#define pi               3.14159265358979323846
#define ll               long long int
#define acc              accumulate
#define ld               long double
#define pb               push_back
#define r0               return 0;
#define pp               pop_back
#define vec              vector
#define sec              second
#define S                string
#define D                double
#define len              length
#define br               break;
#define wh               while
#define fs               first
#define F                float
#define gcd              __gcd
#define sz               size
#define endl              "\n"
#define sp              " "
const ll ifn=-1000000000000000000;
const ll inf=1000000000000000000;
const int N=100000;
ll arr[1000005],n,a[1000005],k;
ll frog(ll i) {
    if(i==n-1) {
        return 0;
    }
    else if(i>n-1) {
        return INT_MAX;
    }
    else {
        if(arr[i]!=-1) {
            return arr[i];
        }
        else {
        //ll r,l;
        //l=abs(a[i]-a[i+1])+frog(i+1);
        //r=INT_MAX;r=abs(a[i]-a[i+2])+frog(i+2);
          ll cnt=INT_MAX,j;
          fr(j,1,k) {
            cnt=min(cnt,abs(a[i]-a[i+j])+frog(i+j));
          }
        return arr[i]=cnt;
        }
    }
}

int main() {
    dude
    memset(arr,-1,1000005);
    cin>>n>>k;
    ll i;
    fr(i,0,n-1) {
        cin>>a[i];
    }
    cout<<frog(0);
   r0
}
