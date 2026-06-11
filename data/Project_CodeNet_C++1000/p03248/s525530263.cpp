#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if(s[n-1]=='1'){
        cout << "-1" << endl;
        return 0;
    }
    if(s[0]=='0'){
        cout << "-1" << endl;
        return 0;
    }
    rep(i,n/2){
        if(s[i]!=s[n-2-i]){
            cout << "-1" << endl;
            return 0;
        }
    }

    int now = 1;
    srep(i,1,n){
        cout << now << ' ' << i+1 << endl;
        if(n%2==0){
            if(n/2<=i){
                if(s[n-1-i]=='1'){
                    now = i+1;
                }
            }
        }else{
            if((n+1)/2<=i){
                if(s[n-1-i]=='1'){
                    now = i+1;
                }
            }
        }
    }

    return 0;
}
 
 
