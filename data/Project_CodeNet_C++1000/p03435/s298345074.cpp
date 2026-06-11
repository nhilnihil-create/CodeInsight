#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    ll x;
//    x=1ll << 59;
//    ll y=(1ll << 59) - 1ll;
//    cout<<((double)(x)==(double)(x-1))<<endl;
    ll l1[4][4];
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>l1[i][j];
        }
    }
    if((l1[1][1]-l1[1][2]==l1[2][1]-l1[2][2] && l1[1][1]-l1[1][2]==l1[3][1]-l1[3][2]) && (l1[1][2]-l1[1][3]==l1[2][2]-l1[2][3] && l1[1][2]-l1[1][3]==l1[3][2]-l1[3][3])){
        if((l1[1][1]-l1[2][1]==l1[1][2]-l1[2][2] && l1[1][1]-l1[2][1]==l1[1][3]-l1[2][3]) && (l1[2][1]-l1[3][1]==l1[2][2]-l1[3][2] && l1[2][1]-l1[3][1]==l1[2][3]-l1[3][3])){
            cout<<"Yes";return 0;
        }
    }
    cout<<"No";
}
