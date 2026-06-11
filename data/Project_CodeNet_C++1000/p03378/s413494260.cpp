#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,x;
    cin>>n>>m>>x;
    int a=0,b=0;
    for(int i=1;i<=m;i++){
        int ch;cin>>ch;
        if(x>ch)a++;
        else b++;
    }
    cout<<min(a,b)<<endl;


    return 0;
}
