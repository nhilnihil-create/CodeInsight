// ABC84-D
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

int n=100000;
vector<bool> is_prime(100010,true);
void hurui(){
    for(int i=2;i<=n;i++){
        int num=2*i,seki=2;
        while(num<=n){
            is_prime[num]=false;
            seki++;
            num=seki*i;
        }
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int q;
    cin>>q;
    is_prime[0]=false,is_prime[1]=false;
    hurui();
    vector<int> rui(100010,0);
    for(int i=3;i<=n;i++){
        if(i%2==0) rui[i]=rui[i-1];
        else{
            if(is_prime[i] && is_prime[(i+1)/2]){
                rui[i]=rui[i-1]+1;
            }else{
                rui[i]=rui[i-1];
            }
        }
    }
    rep(i,q){
        int l,r;
        cin>>l>>r;
        cout<<rui[r]-rui[l-1]<<endl;
    }
    return 0;
}