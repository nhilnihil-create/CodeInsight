#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    if(x%y==0) cout << -1 << endl;
    else{
        for(int i=1;;i++){
            if((x*i)%y==0) continue;
            else{
                cout << x*i << endl;
                return 0;
            }
        }
    }
}
