#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

int main(){
    int n;
    cin >> n;

    vector<string> s(n);

    cout << 0 << endl;
    cin >> s[0];

    if(s[0] == "Vacant"){
        return 0;
    }

    int left = 0, right = n, mid;

    while(true){
        mid = ( left + right) / 2;

        cout << mid << endl;
        cin >> s[mid];

        if(s[mid] == "Vacant"){
            return 0;
        }

        if(s[left] == s[mid] && (mid - left) % 2 == 1){
            right = mid;
        } else if (s[left] != s[mid] && (mid - left) % 2 == 0){
            right = mid;
        } else {
            left=mid;
        }
    }

    return 0;
}