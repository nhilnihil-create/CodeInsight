#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int flag=0;
    while(n>0){
        if(n%7==0){
            flag=1;
            break;
        }
        n-=4;
    }
    if(flag==1||n==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
