#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    float n,t,a,mx=999999; int l=0,i=1; cin>>n>>t>>a;
    while(n--){
            float x; cin>>x;
        float p=t-x*0.006;
        if(abs(p-a)<mx)mx=abs(p-a),l=i;
        i++;
    } cout<<l;
}

