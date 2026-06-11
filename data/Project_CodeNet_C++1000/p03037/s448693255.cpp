#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int l=1,r=n;
    for(int i=0;i<m;i++){
        int ltemp, rtemp;
        cin >> ltemp >> rtemp;
        if(ltemp>l){
            l = ltemp;
        }
        if(rtemp < r){
            r = rtemp;
        }
    }
    if(r<l){
        cout << 0 << endl;
    }else{
        cout << r-l+1 << endl;
    }
}