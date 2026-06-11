#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, dis_x, dis_y, dis_t;
    cin>>n;

    vector<int> t(n+1), x(n+1), y(n+1);
    t[0], x[0], y[0] = 0, 0, 0;
    for(int i=1; i<n+1; i++){
        cin>>t[i]>>x[i]>>y[i];
    }

    for(int i=0; i<n; i++){
        bool odd = false;

        dis_t = t[i+1]-t[i];
        dis_x = abs(x[i+1]-x[i]);
        dis_y = abs(y[i+1]-y[i]);
        
        if((dis_t - (dis_x + dis_y))%2==0){
            odd=true;
        }

        if((dis_x + dis_y) > dis_t){
            cout<<"No"<<endl;
            return 0;
        }else if((dis_x + dis_y) != dis_t){
            if(!odd){
                cout<<"No"<<endl;
                return 0;
            }
        }

    }

    cout<<"Yes"<<endl;
    return 0;
}