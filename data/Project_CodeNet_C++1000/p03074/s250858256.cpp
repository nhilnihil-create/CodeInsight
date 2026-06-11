#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807

#define MOD 1000000007
#define MOD2 998244353

template<class T,class U>bool chmax(T &a, const U &b){if(a<b){a=b;return 1;}return 0;}
template<class T,class U>bool chmin(T &a, const U &b){if(b<a){a=b;return 1;}return 0;}

#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define rep1(i,a,b) for(int a_=(a),b_=(b),i=a_;i<b_;++i)
#define repr(i,n) for(int _i=(n),i=_i;i>0;--i)

#define db(x) cerr<<#x<<" = "<<x<<" ";
#define db2(x,y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<") ";
#define db3(x,y,z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = ("<<x<<", "<<y<<", "<<z<<") ";
#define ln cout<<endl;

#define all(a)  (a).begin(),(a).end()
#define dig(n)  to_string(n).length()

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define se second
#define fi first

typedef long long ll;

typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,P> PP;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<int> ranlen(string s){

    char now = s[0];
    int i=0,count=0,len=s.size();
    vector<int>l;

    while(i < len){
        count=0;
        now = s[i];
        while(s[i]==now  && i < len){
            ++i;
            ++count;
        }

        l.push_back(count);
    }
    return l;
}

int main(){
    bool flag=true;
    ll ans=0,sum=0;

    int n,k;
    string s;
    cin >>n>>k>>s;

    vector<int> r = ranlen(s);
    if(s[0] == '0')r.insert(r.begin(),0);
    if(s[n-1] == '0')r.push_back(0);

    /*
    for (int i = 0; i < r.size(); i++){
        cout << r[i] << " ";
    }
    ln;
    */


    vector<int> sumr( r.size() );
    sumr[0] = r[0];
    
    rep1(i,1,r.size()){
        sumr[i] = sumr[i-1]+r[i];
    }

    int tmp;
    if(r.size()<=2*k){
        ans = n;
    }else{
        
        tmp = sumr[2*k];
        chmax(ans,tmp);

        int p = 2;
        while(p+2*k < r.size()){
            tmp = sumr[p+2*k] - sumr[p-1];
            chmax(ans,tmp);
            p += 2;
        }
    }


    //cout <<fixed<<setprecision(16)<< << endl;
    cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}
