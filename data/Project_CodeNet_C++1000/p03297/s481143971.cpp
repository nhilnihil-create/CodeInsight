#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005
#define yes {cout<<"Yes"<<endl; continue;};
#define no {cout<<"No"<<endl; continue;};

long long int GCD(long long int x, long long int y){
    if(x>y){
        long long int swap = x;
        x = y;
        y = swap;
    }
    while(true){
        if(y%x==0){
            return x;
        }else{
            long long int amari = y%x;
            y = x;
            x = amari;
        }
    }
}

int main() {
    int n;
    cin >> n;
    ll keep[n][4];
    rep(i,n){
        cin >> keep[i][0] >> keep[i][1] >> keep[i][2] >> keep[i][3];
    }
    rep(i,n){
        ll a,b,c,d;
        a = keep[i][0]; b = keep[i][1]; c = keep[i][2]; d = keep[i][3]; 
        if(d < b)no;
        if(b > a)no;
        a -= b;
        if(a<=c)a+=d;
        if(c>=b)yes;
        if(b==d){
            a -= (a/b)*b;
            if(c>=a){
                yes;
            }else{
                no;
            }
        }
        if(a<=c){
            ll x = (c-a) / (d-b);
            a += x * (d-b);
        }
        if(a<=c)a += d-b;
        if(a - c > b){
            ll x = (a-c) / b;
            if((a-c)%b==0){
                x--;
            } 
            a -= b * x;
        }
        a -= b; // ここでc>=a && a>c-b になっているはず
        //cout << a << ' ';
        if(a<0)no;
        ll x = GCD(b,d);
        if((c-a)>=x){
            ll count = (c-a)/x;
            a += count*x;
        }
        if(c>=a)a+=x;
        if(a>=b){
            cout << "Yes" << endl;
            continue;
        }else{
            cout << "No" << endl;
            continue;
        }
    }

    return 0;
}
 
 
