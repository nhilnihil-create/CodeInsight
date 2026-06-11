#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    bool ans = false;
    for(int c=0;4*c<=N;c++){
        for(int d=0;7*d<=N-4*c;d++){
            if(4*c+7*d==N) ans = true;
        }
    }
    if(ans) cout <<"Yes"<<endl;
    if(!ans) cout <<"No" <<endl;
}