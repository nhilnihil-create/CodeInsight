#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
double ans=0;
const double eps=1e-5;
double func(double t,double v,double t2,double time){
    if(t2<=time && t2+t>=time){
        return v;
    }
    else if(t2>time){
        return v+(t2-time);
    }
    else{
        return v+(time-(t2+t));
    }
}
void Main(){
    int n;cin >> n;
    vector<double> t(n+2),v(n+2),t2(n+3,0);
    t[0]=0;v[0]=0;
    For(i,1,n+1) cin >> t[i];
    For(i,1,n+1) cin >> v[i];
    t[n+1]=accumulate(t.begin(),t.end()-1,0.0);v[n+1]=0;
    For(i,1,n+3){
        t2[i]=t2[i-1]+t[i-1];
    }
    double vel=0;
    for(double time=0;time<t[n+1]+eps;time+=0.5){
        double newvel=time;
        For(i,0,n+2){
            newvel=min(newvel,func(t[i],v[i],t2[i],time));
        }
        ans+=(vel+newvel)/4;
        vel=newvel;
    }

    cout << fixed << setprecision(10) << ans << endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}