#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
int n;
string start,res;
int main(){
    cin>>n;
    cout << 0 << endl;
    cin >> start;
    if(start=="Vacant"){
        return 0;
    }
    else if(start=="Male"){
        int l=0,r=n-1;
        while(r>l+1){
            int mid=(r+l)/2;
            if(mid%2==0){
                cout << mid << endl;
                cin >> res;
                if(res=="Vacant") return 0;
                else if(res=="Male"){
                    l=mid;
                }
                else{
                    r=mid;
                }
            }
            else{
                cout<<mid<<endl;
                cin>>res;
                if(res=="Vacant") return 0;
                else if(res=="Male"){
                    r=mid;
                }
                else l=mid;
            }
        }
        cout<<r<<endl;
        cin>>res;
        return 0;
    }
    else if(start=="Female"){
        int l=0,r=n-1;
        while(r>l+1){
            int mid=(r+l)/2;
            if(mid%2==0){
                cout << mid << endl;
                cin >> res;
                if(res=="Vacant") return 0;
                else if(res=="Female"){
                    l=mid;
                }
                else{
                    r=mid;
                }
            }
            else{
                cout<<mid<<endl;
                cin>>res;
                if(res=="Vacant") return 0;
                else if(res=="Female"){
                    r=mid;
                }
                else l=mid;
            }
        }
        cout<<r<<endl;
        return 0;
    }
}