#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

struct edge{int c,s,f;};

int main(){
    int n;
    cin >> n;
    vector<edge> v(n-1);
    rep(i,n-1){
        int a,b,c;
        cin >> a >> b >> c;
        v[i].c = a;
        v[i].s = b;
        v[i].f = c;
    }
    
    for (int i = 0;i < n-1;i++){
        int now = v[i].s;
        now += v[i].c;
        for (int j = i+1;j < n-1;j++){
            int tmp = v[j].s/v[j].f;
            while (tmp*v[j].f < now){
                tmp++;
                //cout << tmp*v[j].f << endl; 
            }
            now = tmp*v[j].f + v[j].c;
        }
        cout << now << endl;;
    }
    cout << 0 << endl;
    

    return 0;
    
}