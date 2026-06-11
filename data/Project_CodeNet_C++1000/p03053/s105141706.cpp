#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
    int H, W;
    cin>>H>>W;
    vector<string> A(H);
    for(int i=0;i<H;++i){
        cin>>A[i];
    }
    queue<pair<int, int> > que;
    queue<int> numque;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            if(A[i][j]=='#'){
                que.push(mp(i, j));
                numque.push(0);
            }
        }
    }
    pair<int, int> state;
    int num;
    int ans = 0;
    while(!que.empty()){
        state = que.front();que.pop();
        num = numque.front();numque.pop();
        if(ans<num) ans = num;
        if((state.fi>0) && (A[state.fi-1][state.se]=='.')){
            A[state.fi-1][state.se] = '#';
            que.push(mp(state.fi-1, state.se));
            numque.push(num+1);
        }
        if((state.fi<H-1) && (A[state.fi+1][state.se]=='.')){
            A[state.fi+1][state.se] = '#';
            que.push(mp(state.fi+1, state.se));
            numque.push(num+1);
        }
        if((state.se>0) && (A[state.fi][state.se-1]=='.')){
            A[state.fi][state.se-1] = '#';
            que.push(mp(state.fi, state.se-1));
            numque.push(num+1);
        }
        if((state.se<W-1) && (A[state.fi][state.se+1]=='.')){
            A[state.fi][state.se+1] = '#';
            que.push(mp(state.fi, state.se+1));
            numque.push(num+1);
        }
    }
    cout<<ans<<endl;
}

