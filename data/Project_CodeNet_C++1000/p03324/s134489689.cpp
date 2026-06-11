#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int d,n;
    cin>>d>>n;
    if(n==100)
        cout<<(long long)(101*pow(100,d))<<endl;
    else
        cout<<(long long)(n*pow(100,d))<<endl;
    return(0);
}