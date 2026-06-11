#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};

int main() {
    ll n;
    cin >>n;
    
    vector<ll> PF(101);
    rep2(i,n){
        ll N=i;
        for (long long a = 2; a * a <= N; ++a) {
            if (N % a != 0) continue;
            long long ex = 0; // 指数
            //cout<<"OK"<<endl;
            // 割れる限り割り続ける
            while (N % a == 0) {
                ++ex;
                N /= a;
            }

            // その結果を push
            PF[a]+=ex;
        }

        // 最後に残った数について
        if (N != 1) PF[N]++;;
    }

    /*rep(i,101){
        cout<<i<<" "<<PF[i]<<endl;
    }*/
    
    vector<ll> CNT(5);
    /*rep(i,101){
        if(PF[i]<=2){
            N75[i][0] = 1;
            TP[i] = 3;
        }
        if(PF[i]<=4){
            N75[i][1] = 1;
            TP[i] = 5;
        }
        if(PF[i]<=14){
            N75[i][2] = 1;
            TP[i] = 15;
        }
        if(PF[i]<=24){
            N75[i][3] = 1;
            TP[i] = 25;
        }
        if(PF[i]<=74){
            N75[i][4] = 1;
            TP[i] = 75;
        }
    }*/

    

    /*rep(i,101){
        if(PF[i]>=74){
            CNT[4]++;
        }else if(PF[i]>=24){
            CNT[3]++;
        }else if(PF[i]>=14){
            CNT[2]++;
        }else if(PF[i]>=4){
            CNT[1]++;
        }else if(PF[i]>=2){
            CNT[0]++;
        }
    }*/
    rep(i,101){
        if(PF[i]>=74){
            CNT[4]++;
        }
        if(PF[i]>=24){
            CNT[3]++;
        }
        if(PF[i]>=14){
            CNT[2]++;
        }
        if(PF[i]>=4){
            CNT[1]++;
        }
        if(PF[i]>=2){
            CNT[0]++;
        }
    }
    ll ans = 0;
    /*ll ans = CNT[0]*CNT[1]*(CNT[1]-1)/2 + CNT[0]*CNT[3] + CNT[1]*CNT[3]+CNT[4];
    ans += CNT[2]*CNT[1]*(CNT[1]-1)/2 + CNT[0]*CNT[2]*(CNT[2]-1)/2 ;
    ans += 
    ans += CNT[0]*CNT[3]*(CNT[3]-1)/2;
    ans += CNT[4]*CNT[1]*(CNT[1]-1)/2+CNT[0]*CNT[4]*(CNT[1]-1)/2+CNT[0]*CNT[4]*(CNT[3]-1)/2;
    ans += */

    /*rep(i,5){
        rep(j,5){
            rep3(k,5){
                if(j==0 ||k==0)continue;
                if(i==j||i==k) continue;
                if(j==k){
                    ans += (CNT[i]*CNT[j]*(CNT[k]-1)/2);
                }else{
                    ans += CNT[i]*CNT[j]*CNT[k];
                }
                
            }
            
        }
    }*/
    /*cout<<ans<<endl;
    rep(i,5){
        rep3(j,i+1,5){
            ans+=(CNT[i]*CNT[j]);
            //cout<<ans<<endl;
            //cout<<CNT[i]<<" "<<CNT[j]<<endl;
        }
    }*/
    //cout<<ans<<endl;
    
    
    ans += CNT[4] + CNT[3]*(CNT[0]-1) + CNT[2]*(CNT[1]-1);
    ans += CNT[1]*(CNT[1]-1)*(CNT[0]-2)/2;
    cout<<ans<<endl;
    return 0;
    

}