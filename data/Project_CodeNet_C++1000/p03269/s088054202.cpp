#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=100000000000000000;

int main() {
    int n,nn;
    cin >> n;
    nn=n;
    vector<int> a(0);
    while (true){
        a.push_back(n%3);
        n/=3;
        if (n==0) break;
    }
    nn=nn-a.at(0);
    int p=a.size()+1;
    vector<pair<pp,int>> f;
    rep(i,a.size()){
        int c=pow(3,i);
        rep(j,a.at(i)){
            f.push_back(mk(mk(i+1,p),nn+j*c));
        }
        
        if (i!=a.size()-1){
            nn-=a.at(i+1)*c*3;
            rep(j,3){
                f.push_back(mk(mk(i+1,i+2),j*c));
            }
        }
    }
    cout << p << " " << f.size() << endl;
    rep(i,f.size()){
        cout << f.at(i).first.first << " " << f.at(i).first.second << " " << f.at(i).second << endl;
    }
}
