#include <bits/stdc++.h>
using namespace std;
namespace Suhaib_Templates {

    #define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #define Alhamdulillah return 0;
    typedef long long ll;
    typedef long double ld;
    #define all(v) v.begin(),v.end()
    #define rall(v) v.rbegin(),v.rend()
    #define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
    #define F_OR1(e) F_OR(i, 0, e, 1)
    #define F_OR2(i, e) F_OR(i, 0, e, 1)
    #define F_OR3(i, b, e) F_OR(i, b, e, (b)<(e)?1:-1)
    #define F_OR4(i, b, e, s) F_OR(i, b, e, s)
    #define GET5(a, b, c, d, e, ...) e
    #define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
    #define lp(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
    #define each(a,x) for (auto& a: x)
    #define pb push_back
    #define ins insert
    #define sz(v) (int) v.size()
     
    ll FirstTrue (ll l,ll r,function<bool(ll)>f) {
        while(l<r){
        ll mid=l+(r-l)/2;
        f(mid)?r=mid:l=mid+1; } 
        return l;
    }
    ll LastTrue(ll l,ll r,function<bool(ll)>f) {
        while(l<r){
        ll mid=l+(r-l+1)/2;
        f(mid)?l=mid:r=mid-1;} 
        return l;
    }
     
    ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
    ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

    // TYPE ID (StackOverflow)
    
    template<class T> struct like_array : is_array<T>{};
    template<class T, size_t N> struct like_array<array<T,N>> : true_type{};
    template<class T> struct like_array<vector<T>> : true_type{};
    template<class T> bool is_like_array(const T& a) { return like_array<T>::value; }
    
    // INPUT 
    
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest);
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);
    
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { re(first); re(rest...); }
    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { lp(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { lp(i,SZ) re(a[i]); }
    
    // OUTPUT 
    
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    template<class T> ostream& printArray(ostream& os, const T& a, int SZ) {
        os << '{';
        lp(i,SZ) {
            if (i) {
                os << ", ";
                if (is_like_array(a[i])) cout << "\n";
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
    template<class T, size_t SZ> ostream& operator<<(ostream& os, const array<T,SZ>& a) {
        return printArray(os,a,SZ);
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        return printArray(os,a,sz(a));
    }
    template<class T> ostream& operator<<(ostream& os, const set<T>& a) {
        os << vector<T>(all(a)); return os;
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {
        os << vector<pair<T1,T2>>(all(a)); return os;
    }
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }

    #define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

    void err(istream_iterator<string> it) {}
    template<typename T, typename... Args>
    void err(istream_iterator<string> it, T a, Args... args) {
        cerr << "[ " << *it << " = " << a << " ]" << '\n';
        err(++it, args...);
    }
     
    const int di[8] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
    const int dj[8] = {1 , -1 , 0 , 0 , 1 , -1 , 1 , -1};

}
using namespace Suhaib_Templates;
 
/***********************************************************/

vector <int> v;
void calc (ll n , bool _7 , bool _5 , bool _3){

    if (n > 1e9)
        return;

    if (_7 & _5 & _3)
    v.pb(n);

    n *= 10;
    calc(n+7,1,_5,_3); 
    calc(n+5,_7,1,_3); 
    calc(n+3,_7,_5,1); 

}

void Suhaib_Sawalha (){

    calc(0,0,0,0);
    sort(all(v));

    int n;
    re(n);
    pr(upper_bound(all(v),n) - v.begin());

}

int main(){
                                In_The_Name_Of_Allah_The_Merciful   /* بسم الله الرحمن الرحيم  */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
// int _;cin>>_;for(int i=1;i<=_;++i,cout<<'\n')
        // cout<<"Case #"<<i<<":\n", 
        Suhaib_Sawalha();
                                         Alhamdulillah                    /* الحمد لله */
}