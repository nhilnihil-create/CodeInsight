#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int t[210],v[210];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    REP(i,n) cin>>t[i];
    REP(i,n) cin>>v[i];
    double ret=0,sp=0;
    REP(i,n){
        for(double j=0;j<t[i];j+=0.5){
            bool flg1=true,flg2=true;
            double ti=t[i]-j-0.5;
            for(int k=i+1;k<n;k++){
                ti+=t[k];
                if(sp+0.5-ti>v[k+1]) flg1=false;
                if(sp-v[k+1]>ti) flg2=false;
            }
            if(sp+0.5<=v[i] && flg1 && (sp+0.5-(t[i]-j-0.5))<=v[i+1]){
                ret+=sp*0.5;
                ret+=0.125;
                sp+=0.5;
            }
            else if(sp-v[i+1]<=t[i]-j-0.5&&flg2) ret+=sp*0.5;
            else{
                sp-=0.5;
                ret+=sp*0.5;
                ret+=0.125;
            }
        }
    }
    printf("%.15lf\n",ret);
}
