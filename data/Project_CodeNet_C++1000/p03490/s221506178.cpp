#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>
#include <cmath>
#include <stack>
#include <iomanip>

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

const ll INF = 1LL<<60;
const ll MOD = 1000000007;

//cout << fixed << setprecision(10);

int main() {
    string s;
    cin >> s;
    vector<int> X,Y;
    int disx,disy;
    cin >> disx >> disy;
    ll N = s.size();
    ll turn = 0;
    ll d1;
    ll ct=0;
    bool first = true;
    for(int i=0;i<N;i++){
        if(s[i]=='T'){
            if(turn==0){
                if(first){
                    d1 = ct;
                    first = false;
                }
                else X.push_back(ct);
                ct = 0;
                turn = 1;
            }
            else{
                Y.push_back(ct);
                ct = 0;
                turn = 0;
            }
        }
        else ct++;
    }
    if(ct!=0){
        if(turn==0) {
            if(first) d1 = ct;
            else X.push_back(ct);
        }
        else Y.push_back(ct);
    }

    vector<vector<int>> dpx(X.size()+10,vector<int>(16010,0));
    vector<vector<int>> dpy(Y.size()+10,vector<int>(16010,0));
    int margin = 8000;
    dpx[0][margin+d1]=1;
    dpy[0][margin]=1;


    for(int i=0;i<X.size();i++){
        for(int j=0;j<2*margin;j++){
            if(dpx[i][j]==1){
                dpx[i+1][j-X[i]]=1;
                dpx[i+1][j+X[i]]=1;
            }
        }
    }

    for(int i=0;i<Y.size();i++){
        for(int j=0;j<2*margin;j++){
            if(dpy[i][j]==1){
                dpy[i+1][j-Y[i]]=1;
                dpy[i+1][j+Y[i]]=1;
            }
        }
    }

    if(dpx[X.size()][margin+disx]==1 && dpy[Y.size()][margin+disy]==1){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    return 0;
}