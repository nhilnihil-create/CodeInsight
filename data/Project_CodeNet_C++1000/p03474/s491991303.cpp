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

// 1 way is to find compute all the sorted permutations and find the 
// positions of the current permutation.

bool _find(string &str,int a,int b){
    int l=str.l();
    if(l!=a+b+1){return false;}
    if(l<a+1){return false;}
    if(str[a]!='-'){return false;}
    for(int i=0;i<str.l();i++){
        if(i==a){continue;}
        if(!isdigit(str[i])){
            return false;
        }
    }
    return 1;
}
void solve(){
    int a,b;
    cin>>a>>b;
    string str;
    cin>>str;
    cout<<(_find(str,a,b)?"Yes":"No")<<endl;
}

int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}