#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main()
{
    int N;
    cin >> N;
    vector<pair<int,int>> pb;
    vector<pair<int,int>> pr;
    vector<bool> used(N,false);

    REP(i,N){
        int a,b;
        cin>>a>>b;
        pr.push_back(make_pair(a,b));
    }   
    REP(i,N){
        int a,b;
        cin>>a>>b;
        pb.push_back(make_pair(a,b));
    }

    sort(pb.begin(),pb.end());

    int cnt=0;
    REP(i,N){
        int xb=pb[i].first;
        int yb=pb[i].second;
        //cout << xb<<" "<<yb << endl;

        int opt_i=-1;
        int max_y=-1;
        REP(j,N){
            if(used[j]) continue;
            int xr=pr[j].first;
            int yr=pr[j].second;
            //cout << xr<<" "<<yr << endl;
            if(xr<xb&&yr<yb){
                if(max_y<yr){
                  //printf("xr:%d yr:%d xb:%d yb:%d\n", xr, yr, xb, yb);
                    max_y=yr;
                    opt_i=j;
                }
            }
        }
        if(opt_i!=-1){
            used[opt_i] = true;
            cnt++;
        }

    }
    cout << cnt << endl;

    
    return 0;
}