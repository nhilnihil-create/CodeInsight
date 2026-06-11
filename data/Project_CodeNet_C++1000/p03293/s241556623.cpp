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

bool isAnagram(string &txt,string &pat){
    vector<int> f1(256,0);
    vector<int> f2(256,0);
    for(int i=0;i<txt.l();i++){
        f1[txt[i]]++;
        f2[pat[i]]++;
    }
    for(int i=0;i<256;i++){
        if(f1[i]!=f2[i]){return false;}
    }
    return true;
}
bool check(string &txt,string &pat){
    if(txt.l()!=pat.l()){return false;}
    if(txt==pat){return 1;}
    if(!isAnagram(txt,pat)){return false;}
    
    for(int l=1;l<=txt.l();l++){
        string a="";
        string b="";
        a=txt.substr(0,l);
        if(l<txt.l()){
            b=txt.substr(l);
        }
        // cout<<b<<" "<<a<<" : "<<b+a<<endl;
        if(b+a==pat){return 1;}
    }
    return false;
}

void solve(){
    string txt,pat;
    cin>>txt>>pat;
    
    if(check(txt,pat)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
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