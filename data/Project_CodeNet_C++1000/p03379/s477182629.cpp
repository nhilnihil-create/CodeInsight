#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    vector<int>y(n);
    for(int i=0;i<n;i++){
        y[i]=x[i];
    }
    sort(y.begin(),y.end());
    for(int i=0;i<n;i++){
        if(x[i]<y[n/2]){
        cout<<y[n/2]<<endl;
        }
        else{
            cout<<y[n/2-1]<<endl;
        }
    }
    return 0;
}