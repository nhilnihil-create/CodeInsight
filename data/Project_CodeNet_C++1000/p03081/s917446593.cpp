#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;
typedef unsigned long long ull;



int main(){
    int n,q;
    cin >> n >> q;
    string a;
    a.push_back('.');
    string s;
    cin >> s;
    a=a+s;
    a.push_back('.');
    vector<pair<char,int>> b(q);
    rep(i,q){
        char f,g;
        cin >> f >> g;
        int u=0;
        if (g=='R') u++;
        b[i]=mk(f,u);
    }
    int l=0,r=n+1,ans=0;
    while(true){
        int mid=(l+r)/2;
        int h=mid;
        char y=a[mid];
        rep(i,q){
            // cout << y << endl;
            if (y==b[i].first) {
                if (b[i].second==1) h++;
                else h--;
                y=a[h];
            }
        }
        // cout << h << endl;
        if (l==r){
            if (h==0) l=mid;
        else l=mid-1;
        break;
        }
        if (h==0) l=mid+1;
        else r=mid;
        // cout << l << " " << r << endl;
    }
    // cout << l << endl;
    ans+=l;
    l=0;r=n+1;
    while(true){
        int mid=(l+r)/2;
        int h=mid;
        char y=a[mid];
        rep(i,q){
            if (y==b[i].first) {
                if (b[i].second==1) h++;
                else h--;
                y=a[h];
            }
        }
        if (l==r){
            if (h==n+1) l=mid;
        else l=mid-1;
        break;}
        if (h==n+1) r=mid;
        else l=mid+1;
    }
    ans+=n+1-l;
    cout << n-ans << endl;
}
