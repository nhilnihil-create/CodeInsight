#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int min=0,max;;
    int n,m;
    cin >> n;
    max = n;
    cin >> m;
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        if(min < l){
            min = l;
        }
        if(max > r){
            max = r;
        }

    }
    if(min <= max){
        cout << max -min + 1 << endl;
    }else{
        cout << 0 << endl;
    }
}