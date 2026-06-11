#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int a[3];
    while(cin>>a[0]>>a[1]>>a[2]){
        sort(a,a+3);
        if(a[0]==a[1]&&a[1]==a[2])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
