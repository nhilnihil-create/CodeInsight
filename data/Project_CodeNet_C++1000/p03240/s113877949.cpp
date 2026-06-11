#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double pi = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

struct point{
    pair<ll,ll> p;
    ll h;
    point(ll x, ll y ,ll H){
        p = make_pair(x,y);
        h = H;
    }
};

int main(){
    ll N;
    cin >> N;
    vector<point> info;
    point ans(0,0,0);
    for(int i = 0; i < N; i++){
        ll x,y,h;
        cin >> x >> y >> h;
        point temp(x,y,h);
        info.emplace_back(temp);
    } 
    for(ll X  = 0; X <= 100 ; X++){
        for(ll Y = 0; Y <= 100; Y++){
            ll H = -1;
            ll min_d = INF;
            bool flag = true;
            for(int i = 0; i < N; i++){
                ll h = info[i].h;
                ll x = info[i].p.first;
                ll y = info[i].p.second;
                ll D = abs(x - X) + abs(y - Y);
                if(h <= 0) min_d = min(min_d , D);
                else{
                    if(H < 0) H = h + D;
                    else if( H != h + D){
                        flag = false;
                        break;
                    } 
                }
            }
            if(flag && H - min_d <= 0){
                cout << X << " " << Y << " " << H << endl;
                return 0;
            }
        }
    }
    return 0;
}
