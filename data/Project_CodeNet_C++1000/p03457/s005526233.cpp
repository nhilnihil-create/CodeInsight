#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> t(n+1),x(n+1),y(n+1);
    for(int i=1;i<=n;i++) cin>>t[i]>>x[i]>>y[i];

    for(int i=1;i<=n;i++){
        int dt=abs(t[i]-t[i-1]);
        int dx=abs(x[i]-x[i-1]);
        int dy=abs(y[i]-y[i-1]);
        if(dx+dy>dt || (dx+dy)%2!=dt%2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}