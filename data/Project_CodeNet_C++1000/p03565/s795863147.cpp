#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define printfdouble(x) printf("%.12f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    string S,T; cin >> S >> T;
    set<string> st;
    rep(i,0,SZ(S)-SZ(T)+1){
        bool flag = true;
        rep(j,0,SZ(T)){
            if(T[j] != S[i+j]){
                if(S[i+j] == '?') continue;
                flag = false;
            }
        }
        if(flag){
            string s;
            rep(j,0,SZ(S)){
                if(j >= i && j < i+SZ(T)){
                    s += T[j-i];
                }else if(S[j] == '?'){
                    s += 'a';
                }else{
                    s += S[j];
                }
            }
            st.insert(s);
        }
    }
    if(st.empty()){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }else{
        string ans = *(st.begin());
        cout << ans << endl;
        return 0;
    }
}