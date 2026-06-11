#include <bits/stdc++.h>
#define INF 1e18
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define MAX 1000
#define ll long long
#define P pair<int,int>
#define cout_set(n) cout << setprecision(10) << (n) << endl; 
const double PI=3.14159265358979323846;
using namespace std;
const int mod = 1000000007; 
int vy[4] ={1,-1,0,0}, vx[4] = {0,0,-1,1}; //up,down,left,right 

int correct(string s,string t){
    int c=1;
    rep(i,t.length()){
        if(s[i] != t[i]){
            if(s[i] != '?'){
                c = -1;
                break;
            }
        }
    }
    return c;
}

signed main(){
    string s,t; cin >> s >> t;
    int start=-1;
    for(int i=0;i<s.length()-t.length()+1;i++){
        if(correct( s.substr(i,t.length()), t) == 1){
            start = i;
        }
    }
    //check
    if(start == -1) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    string ans = s;
    ans.replace(start,t.length(),t);
    rep(i,ans.length()) 
        if(ans[i] == '?') ans.replace(i,1,"a");
    
    cout << ans << endl;
    return 0;
}
