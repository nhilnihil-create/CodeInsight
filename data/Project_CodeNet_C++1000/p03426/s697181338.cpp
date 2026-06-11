#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin,(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int h,w,d;
    cin >> h >> w >> d;
    int a[h][w],total[d];
    map<int,pair<int,int> >m;
    REP(i,h){
        REP(j,w){
            cin >> a[i][j];
            m[a[i][j]] = make_pair(i,j);
        }
    }
    ll answer = 0;
    int q;
    cin >> q;
    int l[q],r[q],left[h*w+1],right[h*w+1];
    REP(i,q){
        cin >> l[i] >> r[i];
    }
    
    FOR(i,0,h*w+1){
        int lx,ly,px,py;
        ly = m[i].first,lx = m[i].second;
            
        
        if(i<=d){
            left[i]=0;
            //continue;
        }
        
        else{
            ly = m[i].first,lx = m[i].second;
            py = m[i-d].first,px = m[i-d].second;
            left[i] = left[i-d]+abs(lx-px)+abs(ly-py);
        }

        //cout << i << " " << lx << " " << ly << endl;
        
    }
    
    FORR(i,h*w,0){
        if(i > h*w-d){
            right[i] = 0;
            continue;
        }
        
        int ly = m[i].first,lx = m[i].second;
        int py = m[i+d].first,px = m[i+d].second;
        right[i] = right[i+d] + abs(lx-px)+abs(ly-py);
    }

    FORR(i,h*w,h*w-d+1){
        total[i%d]=left[i];
    }

    /*REP(i,h*w+1)cout << left[i] << " ";
    cout << endl;
    REP(i,h*w+1)cout << right[i] << " ";
    cout << endl;*/
    
    REP(i,q){
        cout << left[r[i]]+right[l[i]]-total[l[i]%d] << endl;
    }
    
    return 0;
}