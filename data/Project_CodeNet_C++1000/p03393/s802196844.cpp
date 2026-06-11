#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<iomanip>


#define MOD 1000000007
#define INF 1001001001
#define MIN -1001001001
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back
#define PF push_front
#define all(x) (x).begin(),(x).end()


using namespace std;
typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> vv;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    string S;
    cin>>S;
    ll N = S.size();
    map<char,ll> m;
    rep(i,0,N){
        m[S[i]]++;
    }
    if(N!=26)rep(i,0,26){
        if(m['a'+i] == 0){
            cout<<S + char('a'+i);
            return 0;
        }
    }

    vector<char> a;
    a.PB(S[25]);
    char prev = S[25], las = 'Z';
    ll fin = 26;
    for(int i = 24;i>=0;i--){
        if(prev < S[i]){
            a.PB(S[i]);
            prev = S[i];
        }
        else{
            a.PB(S[i]);
            las = S[i];
            fin = i;
            break;
        }
    }
    sort(all(a));
    string ans;
    bool ok = false;
    if(las == 'Z'){
        cout<<-1;
        return 0;
    }
    rep(i,0,fin){
        cout<<S[i];
    }
    for(int i=0; i<a.size();i++){
        if(las < a[i] && !ok){
            ok = true;
            las = a[i];
        }
        else{
            ans+=a[i];
        }
    }
    cout<<las;
    return 0;
}