#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n,p=0,w=0,g=0,y=0;
    char s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=='P' && p!=1)
            p=1;
        if(s=='W' && w!=1)
            w=1;
        if(s=='G' && g!=1)
            g=1;
        if(s=='Y' && y!=1)
            y=1;
    }
    if(p+w+g+y==4)
        cout<<"Four"<<endl;
    else
        cout<<"Three"<<endl;
    return(0);
}