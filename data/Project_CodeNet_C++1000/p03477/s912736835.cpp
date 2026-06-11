#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main( ) {
    //freopen("A.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (a+b<c+d){
        cout << "Right" << endl;
    }
    else if(a+b>c+d){
        cout << "Left" << endl;
    }
    else {
        cout << "Balanced" << endl;
    }
    
    return 0;
}