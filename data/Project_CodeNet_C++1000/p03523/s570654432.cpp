#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;

int main(){
    string s; cin >> s;
    ll n = s.size();
    if(n==5){
        if(s=="KIHBR"){
            puts("YES");
            return 0;
        }
    }else if(n==6){
        if(s=="AKIHBR"||s=="KIHABR"||s=="KIHBAR"||s=="KIHBRA"){
            puts("YES");
            return 0;
        }
    }else if(n==7){
        if(s=="AKIHABR"||s=="AKIHBAR"||s=="AKIHBRA"||s=="KIHABAR"||s=="KIHABRA"
           ||s=="KIHBARA"){
            puts("YES");
            return 0;
        }
    }else if(n==8){
        if(s=="AKIHABAR"||s=="AKIHABRA"||s=="AKIHBARA"||s=="KIHABARA"){
            puts("YES");
            return 0;
        }
    }else if(n==9){
        if(s=="AKIHABARA"){
            puts("YES");
            return 0;
        }
    }else{
        puts("NO");
        return 0;
    }
    puts("NO");
}