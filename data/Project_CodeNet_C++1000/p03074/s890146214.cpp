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
    ll N,K;
    cin>>N>>K;
    string S;
    cin>>S;

    bool is1 = true;
    ll sum = 0;
    v a;
    ll l=0,r=0;
    ll t=-1;
    ll ans = 0;
    while(t<K && r<N){
        if(is1 == true){
            if(S[r] == '1')sum++;
            else{
                ans = max(sum,ans);
                t++;
                sum++;
                if(t == K)sum--;
                is1 = false;
            }
        }
        else{
            if(S[r] == '1'){
                sum++;
                is1 = true;
            }
            else{
                sum++;
            }
        }
        r++;
    }
    r--;
    ans = max(sum,ans);
    while(r<N){
        is1 = true;
        while(1 && l<N){
            if(is1 == true){
                if(S[l] == '1')sum--;
                else{
                    sum--;
                    is1 = false;
                }
            }
            else{
                if(S[l] == '1'){
                    is1 = true;
                    break;
                }
                else{
                    sum--;
                }
            }
            l++;
        }

        is1 = false;
        while(1 && r<N){
            if(is1 == true){
                if(S[r] == '1')sum++;
                else{
                    ans = max(sum,ans);
                    is1 = false;
                    break;
                }
            }
            else{
                if(S[r] == '1'){
                    sum++;
                    is1 = true;
                }
                else{
                    sum++;
                }
            }
            r++;
        }
    }
    ans = max(sum,ans);
    cout<<ans;
    return 0;
}