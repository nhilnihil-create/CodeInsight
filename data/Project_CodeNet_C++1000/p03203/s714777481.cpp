#include <bits/stdc++.h>

using namespace std;

int n,m;
int i,j,k;
string str;
int h,w;

int main(){
    cin >> w >> h >> n;
    vector<pair<int,int> > b(n);
    vector<vector<int> > f(w);
    for(i = 0;i < n;i++){
        int x,y;
        cin >> x >> y;
        x--;y--;
        b[i] = make_pair(x,y);
    }
    sort(b.begin(),b.end());
    for(i = 0;i < n;i++){
        f[b[i].first].push_back(b[i].second);
    }
    int s = 1;
    int a = w;
    for(i = 1;i < w;i++){
        if(f[i].size() > 0){
            if(f[i][0] < s){
                a = i;
                break;
            }
            if(f[i][0] == s) s--;
        }
        s++;
    }
    cout << a << endl;
}
