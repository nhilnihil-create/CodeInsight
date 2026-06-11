#include <iostream>
#include <algorithm>
using namespace std;

long long N, t[100100], x[100100], y[100100], dt, dx, dy;
bool valid=true;

int main() {
    cin >> N;
	for (int i=1; i<=N; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    for (int i=1; i<=N; i++){
        dt = t[i]-t[i-1];
        dx = abs(x[i]-x[i-1]);
        dy = abs(y[i]-y[i-1]);
        
        if (((dx+dy-dt)%2==0) && (dt>=dx+dy)){
            valid = true;
        }
        else{
            valid=false;
            break;
        }
    }
    if (valid == true){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
