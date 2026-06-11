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

bool isUpper(char ch){
    return ch>='A' && ch<='Z';
}
int _find(string &str){
    if(str[0]!='A'){return 0;}
    int cntC=0;
    for(int i=1;i<str.l();i++){
        if(i>=2 && i<=str.l()-1-1){
            if(str[i]=='C'){
                cntC++;
            }
            else{
                if(isUpper(str[i])){
                    return false;
                }
            }
        }
        else{
            if(isUpper(str[i])){
                return false;
            }
        }
    }
    return cntC==1;
}



void solve(){
    
    string str;
    cin>>str;
    if(_find(str)){
        cout<<"AC";
    }
    else{
        cout<<"WA";
    }
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