#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int ans=0;
    for (int i = 0; i < 4; i++){
        char c; cin>>c;
        if(c=='+'){
            ans++;
        }else{
            ans--;
        }
    }
    cout<<ans<<endl;
}

    