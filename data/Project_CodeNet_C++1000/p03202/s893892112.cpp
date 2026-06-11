#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;
typedef vector<lint> poly;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

const lint mod = 998244353;
const lint INF = mod*mod;
const int MAX = 200010;

int n, a[MAX];

void push_word(stack<pii> &st, int c, int L){
    if(L==0) return;
    else if(!st.empty() && st.top().fi==c) st.top().se+=L;
    else st.emplace(c, L);
}

bool check(int m){
    if(m==0) return false;
    stack<pii> st;
    rep(i, n){
        if(i==0) push_word(st, 0, a[0]);
        else if(a[i]>a[i-1]){
            push_word(st, 0, a[i]-a[i-1]);
        }
        else{
            int len=a[i-1];
            while(len-st.top().se>=a[i]){
                len-=st.top().se;
                st.pop();
            }
            while(!st.empty() && st.top().fi+1==m){
                len-=st.top().se;
                st.pop();
            }
            if(len==0) return false;
            pii p=st.top(); st.pop();
            if(len>a[i]){
                int l=len-a[i];
                push_word(st, p.fi, p.se-l-1);
                push_word(st, p.fi+1, 1);
            }
            else{
                push_word(st, p.fi, p.se - 1);
                push_word(st, p.fi + 1, 1);
                push_word(st, 0, a[i]-len);
            }
        }
    }
    return true;
}

int main(){
    scanf("%d", &n);
    rep(i, n) scanf("%d", &a[i]);
    int low=0, high=n;
    while(high-low>1){
        int mid=(high+low)/2;
        (check(mid)?high:low)=mid;
    }
    printf("%d\n", high);
}