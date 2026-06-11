#include <bits/stdc++.h>

using namespace std;

typedef long long               ll;
typedef unsigned long long      ull;
typedef vector<int>             vi;
typedef vector<ll>              vll;
typedef pair<ll,ll>             pairll;
typedef map<ll,ll>              mapll ;
typedef map<char,ll>            mapch;
typedef map<string,ll>          mapstr;

#define si(a) scanf("%d", &a)
#define sll(a) scanf("%lld",&a)
#define sii(a,b) scanf("%d %d", &a,&b)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pt(a) printf("%d",a)
#define pll(a) printf("%lld",a)
#define ps printf(" ")
#define nln printf("\n")
#define pi acos(-1)
#define spc " "
#define nl "\n"
#define rep(i,W) for(int i = 0; i < W; i++)
#define rep1(i,W) for(int i = 1; i <= W; i++)

ll w;
string s;
vector <char> arr;

void input(){
    getline(cin,s);
    cin >> w;
}

void solve(){
    for(ll i = 0; i < s.size(); i+= w)
    {
        if(i%w==0){
            char c = s[i];
            arr.pb(c);
        }
    }
    for(int i = 0; i < arr.size(); i++){
        printf("%c",arr[i]);
    }
    printf("\n");
}

int main(){
    input();
    solve();
    return 0;
}



