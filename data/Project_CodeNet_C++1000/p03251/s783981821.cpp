#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,m,X,Y;
	cin >> n >> m >> X >> Y;
	int mx = -101;
	int my = 101;
	rep(i,n){
        int x;
		cin >> x;
		mx = max(mx,x);
	}
    rep(i,n){
        int y;
        cin >> y;
		my = min(my,y);
	}
    int z = min(X+1,mx);
    for(z;z <= min(Y,my);z++){
        if(X < z && mx < z && z <= Y && z <= my){
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
}