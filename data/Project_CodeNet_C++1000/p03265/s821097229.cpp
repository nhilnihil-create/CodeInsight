#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

const int MOD = 1000000007;
const int INF = 1001001001;

int main(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    
    vi arrow = {-y2+y1, x2-x1};
    
    cout << x2+arrow[0];
    cout << " ";
    cout << y2+arrow[1];
    cout << " ";
    cout << x1+arrow[0];
    cout << " ";
    cout << y1+arrow[1];
    cout << endl;
    return 0;
}