#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=100000;i++){
        if(i*i>n){
            cout<<(i-1)*(i-1)<<endl;
            return(0);
        }
    }
    return(0);
}