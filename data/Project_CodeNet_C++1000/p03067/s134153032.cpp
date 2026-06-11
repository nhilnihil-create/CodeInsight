#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main() {
    int a[3],b[3];
    rep(i,3){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+3);
    if(a[1]==b[2])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
}