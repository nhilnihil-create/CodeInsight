#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> t(n),x(n),y(n);
    for(int i=0;i<n;++i) cin>>t[i]>>x[i]>>y[i];

    int sx=0;
    int sy=0;
    int ct=0;
    bool flag=true;

    for(int i=0;i<n;++i){
        int dx=x[i]-sx;
        int dy=y[i]-sy;
        dx=dx>0?dx:-dx;
        dy=dy>0?dy:-dy;
        if(t[i]-ct<dx+dy){
            flag=false;
            break;
        }
        else if((t[i]-ct-dx-dy)%2!=0){
            flag=false;
            break;
        }
        sx=x[i];
        sy=y[i];
        ct=t[i];
    }

    string ans=flag?"Yes":"No";
    cout<<ans<<endl;
}