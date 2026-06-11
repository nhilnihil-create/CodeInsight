#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    int N = in();
    vector<int> two = {65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};
    int counter = 0;
    cout << 0 << "\n";
    cout.flush();
    string mae = in<string>();
    int now = 0;
    int plus = 1;
    while(1){
        if(mae == "Vacant")break;
        if(two[counter] >= N){
            counter++;
            continue;
        }
        if(plus)if(now + two[counter] >=N){
            counter++;
            continue;
        }
        if(plus){
            now += two[counter];
            cout << now << "\n";
            cout.flush();
        }else{
            now -= two[counter];
            cout << now << "\n";
            cout.flush();
        }
        string cat = in<string>();
        if(cat == "Vacant"){
            break;
        }else if(cat == mae){
            mae = cat;
            plus = 1;
        }else{
            plus = 0;
        }
        counter++;
    }
}