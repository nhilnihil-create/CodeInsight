#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,ans=0;
    bool po=false;
    cin>>a>>b>>c;
    while(1){
        if(!po){
            if(c){
                c--;
                ans++;
                po=true;
                continue;
            }
            break;
        }
        if(po){
            if(b){
                b--;
                ans++;
                po=false;
                continue;
            }
            if(a){
                a--;
                po=false;
                continue;
            }
            break;
        }
    }
    cout<<ans+b;
}
