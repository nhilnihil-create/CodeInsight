// ABC106-D
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define e_b emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v) //vectorの中身を見る
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
void map_p(map<int,int>& d){cout<<"map: ";for(auto a : d){cout<<"{"<<a.first<<":"<<a.second<<"}";}cout<<endl;} //mapの中身を見る
void set_p(set<int>& d){cout<<"set: ";for(int a : d){cout<<a<<" ";}cout<<endl;} //setの中身を見る


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> info(510,vector<int>(510,0));
    vector<vector<int>> yoko(510,vector<int>(510,0));
    vector<vector<int>> tate(510,vector<int>(510,0));
    rep(i,m){
        int l,r;
        cin>>l>>r;
        info[l][r]++;
    }
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            yoko[i][j]=yoko[i][j-1]+info[i][j];
        }
    }
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            tate[i][j]=tate[i-1][j]+yoko[i][j];
        }
    }
    rep(i,q){
        int ll,rr;
        cin>>ll>>rr;
        int ans=tate[rr][rr]-(tate[rr][ll-1]+tate[ll-1][rr]-tate[ll-1][ll-1]);
        cout<<ans<<endl;
    }
    return 0;
}