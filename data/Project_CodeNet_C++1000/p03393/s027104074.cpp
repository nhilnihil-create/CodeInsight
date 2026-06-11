#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define repin(a,n) vector<ll> a(n);rep(i,n){cin>>a[i];}
#define repins(a,n) vector<string> a(n);rep(i,n){cin>>a[i];}
#define repind(a,n) vector<double> a(n);rep(i,n){cin>>a[i];}
#define in(a) ll a;cin>>a;
#define ins(a) string a;cin>>a;
#define ind(a) double a;cin>>a;
template <class T>
inline void out(T a) { cout << a << endl; }
inline void out(double a) { printf("%.10f\n", a); }
#define all(x) (x).begin(), (x).end()
#define rep2(i, a, b) for (ll i = (a); i < (b); ++i)
#define yes out("Yes");
#define no out("No");

int main()
{
    ins(s);

    if(s.size()<26){
        unordered_map<char,bool> dic;
        
        rep(i,s.size()){
            dic.emplace(s[i],true);
        }

        rep(i,26){
            if(dic.count('a'+i)==0){
                s = s + string{(char)('a'+i)};
                out(s);
                return 0;
            }
        }
    }else{
        if(s=="zyxwvutsrqponmlkjihgfedcba"){
            out(-1);
            return 0;
        }

        auto t = s;
        next_permutation(all(s));

        rep(i,s.size()){
            cout << s[i];
            if(s[i]!=t[i]){
                break;
            }
        }
        cout << endl;
    }
}