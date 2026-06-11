#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int x,y;
    cin>>x>>y;
    if(x%y==0){cout<<-1<<endl; return 0;}
    int cnt=0;
    while(1){
        cnt+=x;
        if(cnt%y!=0){
            break;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
