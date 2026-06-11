#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;
    
    int T=0,px=0,py=0;
    for(int i=0;i<n;i++){
        int t,x,y;
        cin>>t>>x>>y;
        int dt=t-T;
        int dxy=abs(x-px)+abs(y-py);
        if(dt<dxy || dt%2!=dxy%2){
            cout<<"No"<<endl;
            return 0;
        }
        T=t;px=x;py=y;
    }
    cout<<"Yes"<<endl;
    return 0;
}
