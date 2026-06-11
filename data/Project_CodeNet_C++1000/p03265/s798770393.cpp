#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    int a,c,b,d;
    cin>>a>>b>>c>>d;
    int hor=(a-c);
    int ver=(b-d);
    cout<<c+ver<<' '<<d-hor<<' '<<a+ver<<' '<<b-hor;
}

