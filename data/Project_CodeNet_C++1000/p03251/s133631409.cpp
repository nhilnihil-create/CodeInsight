#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m,x,y;cin>>n>>m>>x>>y;
    int a[n],b[m];

    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<m;++i){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    int ans=0;
    if(a[n-1]<b[0]){
        for(int i=a[n-1]+1;i<=b[0];++i){
            if(x<i && y>=i){
                ans=1;
                break;
            }
        }
    }
    if(ans==1) cout<<"No War"<<endl;
    else    cout<<"War"<<endl;
	return 0;
}