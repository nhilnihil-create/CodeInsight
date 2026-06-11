#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 10000000
int main()
{
    int h,w;
    cin >> h >> w;
    Graf c(10,vector<int>(10));
    Graf a(h,vector<int>(w));
    Graf dj(10,vector<int>(10));
    vector<bool> flag(10);
    vector<int> count(10,0);
    rep(i,10){
        rep(j,10){
            cin >> c[i][j];
        }
    }
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    rep(i,10){
        rep(j,10){
            dj[i][j]=MAX;

        }
    }

    FOR(i,10,0){
        rep(j,10){
            flag[j]=false;
        }
        int min_val=0;
        int min_j=i;
        flag[i]=true;
        if(i!=1)
            dj[i][i]=MAX;
        else{
            dj[i][i]=0;
        }
        while(!flag[1]){
            
            rep(l,10){
                if(flag[l]==false){
                    dj[i][l]=min(dj[i][l],c[min_j][l]+min_val);
                }
            }
            int tmp_min=MAX;
            int tmp_j;
            rep(l,10){
                if(!flag[l])
                    if(tmp_min>dj[i][l]){
                        tmp_min=dj[i][l];
                        tmp_j=l;                    
                    }
                
            }

            min_val=tmp_min;
            min_j=tmp_j;
            flag[min_j]=true;
        }
    }

    rep(i,h){
        rep(j,w){
            if(a[i][j]!=-1){
                count[a[i][j]]++;
            }
        }
    }
    int ans=0;
    rep(i,10){
        ans+=count[i]*dj[i][1];
    }
    cout << ans << endl;
}