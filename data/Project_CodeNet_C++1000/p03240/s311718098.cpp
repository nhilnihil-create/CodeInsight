#include<bits/stdc++.h>
using namespace std;
int main(){
    long n;
    cin >> n;
    long x[n];
    long y[n];
    long h[n];
    int ansx=0;
    int ansy=0;
    long ansh=0;
    for(int i=0;i<n;i++)cin >> x[i] >> y[i] >> h[i];
    for(int xx = 0;xx<=100;xx++){
        for(int yy=0;yy<=100;yy++){
            bool chk=true;
            int ii=0;
            while(h[ii]==0){
                ii++;
            }
            long tmph = h[ii] + abs(xx-x[ii]) + abs(yy-y[ii]);
            for(int i=0;i<n;i++){
                if(h[i] != max(0L,tmph-abs(xx-x[i])-abs(yy-y[i]))){
                    chk=false;
                    break;
                }
            }
            if(chk){
                ansx=xx;
                ansy=yy;
                ansh=tmph;
                goto xxxx;
            }
            
        }
    }
    xxxx:
    cout<<ansx<<" "<<ansy<<" "<<ansh<<endl;
    
}