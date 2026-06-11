#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    int aa=0,bb=0,cc=0;
    for(int i=0;i<n;i++){
        int p;
        cin >> p;
        if(p<=a) aa++;
        else if(p>=b+1) bb++;
        else cc++;
    }
    cout << min({aa,bb,cc}) << endl;
}
