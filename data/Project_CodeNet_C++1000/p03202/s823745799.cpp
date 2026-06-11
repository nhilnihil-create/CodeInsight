#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6+10;
const ll LINF=1e18;
using namespace std;
    
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl
#define doublecout(a) cout<<fixed<<setprecision(15)<<a<<endl;
#define Cerr(x) cerr<<(x)<<endl
#define fi first
#define se second
#define P pair<ll,ll> 
#define m_p make_pair
#define V vector<ll> 
#define U_MAP unordered_map<ll,ll>
#define pq priority_queue<ll>
#define rpq priority_queue<ll,vector<ll>,greater<ll>>
#define p_b push_back
    
ll n,cnt,ans,a[ohara],b,c,d,tmpp,m,h,w,x,y,sum,pos,k,q;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};
    
//------ Believe yourself as a genius!!!!!! ------

bool check(ll syu){
    int res=1;
    priority_queue<P> que;
    rrep(i,1,n){
        if(res==0)break;
        if(a[i]>a[i-1])continue;
        while(1){
            if(que.empty())break;
            P X=que.top();
            if(X.fi<a[i])break;
            que.pop();
        }
        ll want_ind=a[i]-1;
        int ok=0;
        while(1){
            if(que.empty())break;
            P X=que.top();
            if(want_ind==X.fi&&X.se==syu-1){
                want_ind--;
                que.pop();
            }
            else{
                if(want_ind==X.fi){
                    que.pop();
                    que.push({X.fi,X.se+1});
                    ok=1;
                }
                break;
            }
        }
        if(want_ind<0){
            res=0;
        }
        if(!ok){
            if(want_ind<0){
                res=0;
            }
            else{
                if(syu==1)res=0;
                que.push({want_ind,1});
            }
        }
    }
    if(res==1)return true;
    else return false;
}
    
int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;
    rep(i,n)cin>>a[i];
    ll le=1,ri=LINF,mid;
    while(ri-le>1){
        mid=(le+ri)/2;
        if(check(mid))ri=mid;
        else le=mid;
    }
    rrep(i,max(le-5,1LL),ri+5){
        if(check(i)){
            Cout(i);
            break;
        }
    }
    return 0;
}