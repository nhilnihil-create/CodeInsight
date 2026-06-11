#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,d;
    cin >> a >> b >> c >> d;
    int s = b-a;
    if(s<0){
      s = -s;
    }
    int t = c-b;
    if(t<0){
      t = -t;
	}
    int u = c-a;
    if(u<0){
      u = -u;
    }
    if((s <= d && t <= d) || (u <= d)){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
}
