#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
    int n;cin>>n;
    string a[n];
    int b[n];
    vector<string>c;

    
    string tmp;

    rep(i,n){
        cin>>a[i];
        c.push_back(a[i]);
        b[i]=a[i].size();
    }

    sort(c.begin(),c.end());
    
    rep(i,n-1){
        if(a[i+1][0]!=a[i][b[i]-1] ||c[i+1]==c[i]){
            cout<<"No"<<endl;
//          cout<<a[i+1][0]<<" "<<a[i][b[i]-1]<<endl;
            return 0;
        }
    }
    
    cout<<"Yes"<<endl;
	return 0;
}