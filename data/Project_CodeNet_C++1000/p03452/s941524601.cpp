#include <iostream>
#include <vector>
#define INIT 1e9+7
using namespace std;
typedef pair<int, int> P;
int c[100000];
vector<P> v[100000];
bool f(int x){
    for(int i=0;i<v[x].size();i++){
        int y = v[x][i].first, z = v[x][i].second;
        if(c[y] == INIT){
            c[y] = c[x] + z;
            if(!f(y))return false;
        }else if(c[y] != c[x] + z){
            return false;
        }
    }
    return true;
}
int main(void){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;
        v[l].push_back(P(r,  d));
        v[r].push_back(P(l, -d));
    }
    for(int i=0;i<n;i++){
        c[i] = INIT;
    }
    for(int i=0;i<n;i++){
        if(c[i] == INIT){
            c[i] = 0;
            if(!f(i)){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
