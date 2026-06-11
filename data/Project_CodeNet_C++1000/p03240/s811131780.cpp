#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int n; cin >> n;
    vector<T> pi(n);
    rep(i,n){
        int x,y,h; cin >> x >> y >> h;
        pi[i]=T(x,y,h);
    }

    int nowx,nowy,height;

    queue<T> q;

    rep(i,n){
        tie(nowx,nowy,height)=pi[i];
        if(height==0) continue;
        break;
    }

    rep(i,101){
        rep(j,101){
            int nowh=abs(nowx-i)+abs(nowy-j)+height;
            q.push(T(i,j,nowh));
        }
    }
    int l=q.size();
        while(l--){
            int a,b,c;
            tie(a,b,c)=q.front();
            q.pop();
            rep(i,n){
                tie(nowx,nowy,height)=pi[i];
                if(height==0){
                    if(abs(nowx-a)+abs(nowy-b)<c) break;
                }
                else{
                int nowh=abs(nowx-a)+abs(nowy-b)+height;
                if(nowh!=c) break;
                }
                if(i==n-1){
                    cout << a << ' ' << b << ' ' << c << endl;
                    return 0;
                }
            }
        }

return 0;
}
