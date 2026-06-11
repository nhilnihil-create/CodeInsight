#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 10000;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
static const double pi = 3.141592653589793;





int main(){
    ll H, W;
    cin>>H>>W;
    vector<vector<char>> S(H, vector<char>(W));
    vector<vector<ll>> Visit(H, vector<ll>(W, INF));
    ll White=0;
    rep(i, H){
        rep(j, W){
            cin>>S[i][j];
            if(S[i][j]=='.')White++;
        }
    }
    if(S[0][0]=='#'||S[H-1][W-1]=='#'){
        cout<<-1<<endl;
        return 0;
    }
    Visit[0][0]=0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(make_pair(0, 0));
    while(!Q.empty()){
        pair<ll, ll> P=Q.top(); Q.pop();
        ll v=P.second;//cout<<v<<endl;
        if(Visit[v/W][v%W]<P.first)continue;
        ll x, y;
        x=v/W;
        y=v%W;
        for(ll i=-1; i<=1; i++){
            for(ll j=-1; j<=1; j++){
                if((i*j)!=0)continue;
                if(i==0&&j==0)continue;
                if((x+i)<0||(x+i)>=H)continue;
                if((y+j)<0||(y+j)>=W)continue;
                if(S[x+i][y+j]=='#')continue;
              	//cout<<x<<" "<<y<<" "<<Visit[x+i][y+j]<<" "<<Visit[x][y]<<" "<<x+i<<" "<<y+j<<endl;
                if(Visit[x+i][y+j]>Visit[x][y]+1){
                    Visit[x+i][y+j]=Visit[x][y]+1;
                    Q.push(make_pair(Visit[x+i][y+j],(x+i)*W+y+j));
                  	//cout<<(x+i)*W+y+j<<endl;
                }
            }
        }    
    }
  	/*rep(i, H){
        rep(j, 20){
            cout<<Visit[i][j]<<" ";
        }
      	cout<<endl;
    }*/
    if(Visit[H-1][W-1]==INF){
        cout<<-1<<endl;
        return 0;
    }
  	
    cout<<White-Visit[H-1][W-1]-1<<endl;
  	
}
    