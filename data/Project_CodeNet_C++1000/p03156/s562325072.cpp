#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b; cin>>n>>a>>b;
    int aika=0,aida=0,bkoe=0;
    for(int i=0; i<n; i++){
        int p; cin>>p;
        if(p<=a) aika++;
        else if(b+1<=p) bkoe++;
        else aida++;
    }
    cout << min(min(aika,aida),bkoe) << endl;
}