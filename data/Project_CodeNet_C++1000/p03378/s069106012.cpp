#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x;
    cin >> n >> m >> x;
    
    int right(0),left(0);
    for(int i=0;i<m;i++){
        int a;  cin >> a;
        if(a<x){
            left++;
        }else{
            right++;
        }
    }
    
    cout << min(right,left) << endl;
    
    return 0;
}
