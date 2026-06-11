#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
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
const int inf=1e9+7;
const ll mod=1e9+7;

int main() {
    int N;
    cin>>N;
    vector<pair<int, int> > red;
    vector<pair<int, int> > blue;
    int a, b, c, d;
    for(int i=0;i<N;++i){
        cin>>a>>b;
        red.push_back(make_pair(a, b));
    }
    for(int i=0;i<N;++i){
        cin>>c>>d;
        blue.push_back(make_pair(c, d));
    }
    sort(red.begin(), red.end(), greater<pair<int, int> >());
    sort(blue.begin(), blue.end(), greater<pair<int, int> >());
    int ans = 0;
    map<int, int> usedblue;
    int index;
    int miny;
    bool tmpans;
    for(int i=0;i<N;++i){
        miny = 300;
        tmpans = false;
        for(int j=0;j<N;++j){
            if((usedblue[j]==0) & (miny > blue[j].se) & (red[i].fi < blue[j].fi) & (red[i].se < blue[j].se)){
                index = j;
                miny = blue[j].se;
                tmpans = true;
            }
        }
        if(tmpans){
            usedblue[index]++;
            ans++;
        }
    }
    cout<<ans<<endl;
}

