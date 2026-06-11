#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,A;
    bool  ans=false;
    cin >> N >> A;
    for(int i=0;i<=A;i++){
        if((N%500)==i){
            ans = true;
            break;
        }
    }
    if(ans) cout << "Yes" << endl;
    if(!ans) cout <<"No" <<endl;
    return 0;
}