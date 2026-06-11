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
void YN(bool ans){
    if(ans)cout<<"YES"<<endl;
    else cout <<"NO"<<endl;
    return;
}
int main(){
    string S;
    cin>>S;
    bool ans = false;
    if(S == "KIHBR")ans = true;
    if(S == "AKIHBR")ans = true;
    if(S == "KIHABR")ans = true;
    if(S == "KIHBAR")ans = true;
    if(S == "KIHBRA")ans = true;
    if(S == "AKIHABR")ans = true;
    if(S == "AKIHBAR")ans = true;
    if(S == "AKIHBRA")ans = true;
    if(S == "KIHABAR")ans = true;
    if(S == "KIHABRA")ans = true;
    if(S == "KIHBARA")ans = true;
    if(S == "AKIHABAR")ans = true;
    if(S == "AKIHABRA")ans = true;
    if(S == "AKIHBARA")ans = true;
    if(S == "KIHABARA")ans = true;
    if(S == "AKIHABARA")ans = true;

    YN(ans);
    return 0;
}