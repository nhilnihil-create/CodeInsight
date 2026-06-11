#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("YES")
#define p_no() p("NO")

template < typename T >
void vprint(T &V){
	for(auto v : V){
    	cout << v << " ";
	}
	cout << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    string s;
    cin >> s;
    ll L = s.size();
    char center_char = s[L/2];
    ll count = 0;
        
    if(L%2==0){
        // 真ん中から両端へ
        FOR(i, 0, L/2){
            ll r = L/2 + i;
            ll l = L/2 - 1 - i;
            char right = s[r];
            char left = s[l];
            if(right==left && right==center_char){
                count++;
            }else{
                break;
            }
        }
        p(L/2 + count);
    }
    else{
        ll N = (L-1)/2;
        ll K = L/2 + 1; // 絶対に達成できるK
        FOR(i, 1, N+1){
            ll r = L/2 + i;
            ll l = L/2 - i;
            char right = s[r];
            char left = s[l];
            if(right == left && right==center_char){
                count++;
            }else{
                break;
            }
        }    
        p(K+count);
    }

    
    return 0;
}