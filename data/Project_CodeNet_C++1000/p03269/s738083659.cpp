#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L;
    cin>>L;
    if(L<=7){
        cout <<L+1<<" "<<2*L-1<<"\n";
        rep(i,2,L+2) cout <<1<<" "<<i<<" "<<0<<"\n";
        rep(i,2,L+1)cout <<i<<" "<<i+1<<" "<<1<<"\n";
    }
    else{
        int res=1;
        int s=0;
        while(res<L){
            res*=2;
            s++;
        }
        if(res==L){
            cout <<s<<" "<<2*s<<"\n";
            rep(i,1,s){
                cout <<s-i<<" "<<s+1-i<<" "<<0<<"\n";
                cout <<s-i<<" "<<s+1-i<<" "<<(i<=2?pow(2,i-1):pow(2,i))<<"\n";
            }
            cout <<s-2<<" "<<s-1<<" "<<4<<"\n";
            cout <<s-2<<" "<<s-1<<" "<<6<<"\n";
        }
        else{
            vector<pair<P,int>> v;
            rer(i,20,1){
                if(L&1<<i){
                    if(i>=3){
                        v.pb(make_pair(P(s,i),L-(1<<i)));
                        L-=1<<i;
                    }
                    if(i<3){
                        while(L>=2){
                            v.pb(make_pair(P(s,i),L-(1<<(i-1))));
                            L-=1<<(i-1);
                        }
                    }
                }
            }
            if(L==1) v.pb(make_pair(P(s,1),0));
            cout <<s<<" "<<2*s-2+v.size()<<"\n";
            rep(i,1,s-1){
                cout <<s-i<<" "<<s+1-i<<" "<<0<<"\n";
                cout <<s-i<<" "<<s+1-i<<" "<<(i<=2?pow(2,i-1):pow(2,i))<<"\n";
            }
            cout <<s-2<<" "<<s-1<<" "<<4<<"\n";
            cout <<s-2<<" "<<s-1<<" "<<6<<"\n";
            rep(i,0,v.size()){
                cout <<s+1-v[i].fr.fr<<" "<<s+1-v[i].fr.sc<<" "<<v[i].sc<<"\n";
            }
        }
    }
}