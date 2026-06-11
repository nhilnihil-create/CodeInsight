#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;


int main(){
    vector<set<int>> a(8010),b(8010);
    a.at(0).insert(0);b.at(0).insert(0);
    string s;
    cin >> s;
    int x,y;
    cin >> x >> y;
    int aa=1,bb=1,n=0,c=0;
    rep(i,s.size()){
        if (s.at(i)=='F') c++;
        if (s.at(i)=='T') {
            if (n==0){
                for (auto itr=a.at(aa-1).begin();itr!=a.at(aa-1).end();++itr){
                    if (aa==1) a.at(aa).insert(*itr+c);
                    else {a.at(aa).insert(*itr+c);
                    a.at(aa).insert(*itr-c);}
                    //cout << aa << " " << *itr << endl;
                }
                aa++;
            }
            else{
                for (auto itr=b.at(bb-1).begin();itr!=b.at(bb-1).end();++itr){
                    b.at(bb).insert(*itr+c);
                    b.at(bb).insert(*itr-c);
                    //cout << bb << " " << *itr << endl;
                }
                bb++;
            }
            c=0;n=1-n;
        }
    }
    if (n==0){
                for (auto itr=a.at(aa-1).begin();itr!=a.at(aa-1).end();++itr){
                    if (aa==1) a.at(aa).insert(*itr+c);
                    else {a.at(aa).insert(*itr+c);
                    a.at(aa).insert(*itr-c);}
                    //cout << aa << " " << *itr << endl;
                }
                aa++;
            }
            else{
                for (auto itr=b.at(bb-1).begin();itr!=b.at(bb-1).end();++itr){
                    b.at(bb).insert(*itr+c);
                    b.at(bb).insert(*itr-c);
                    //cout << bb << " " << *itr << endl;
                }
                bb++;
            }
    
    if (a.at(aa-1).find(x)!=a.at(aa-1).end() && b.at(bb-1).find(y)!=b.at(bb-1).end()) cout << "Yes" << endl;
    else cout << "No" << endl;
}