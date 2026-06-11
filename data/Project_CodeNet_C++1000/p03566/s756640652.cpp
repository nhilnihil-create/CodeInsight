#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;


int main() {
    const long long int mod = 1000000007,INF=50000000000000;
	map<long long int, long long int>mp;
	cout << fixed << setprecision(10);
    string str[120];
    long long int n,speed=0,t[600]={},v[600],nowt=1,x1,x2,y1,y2;
    long double res=0.0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    v[n+1]=0;
    for(int i=1;i<=n+1;i++){
        t[i]=t[i]+t[i-1];
    }

    for(int i=1;i<=t[n+1];i++){
        long long int tmp=999999,tmp2=999999;
        for(int j=nowt;j<=n;j++){
            tmp=min(tmp,t[j]-i+v[j+1]);
            tmp2=min(tmp2,2*t[j]-2*i+1+2*v[j+1]);
        }
        if(tmp>=speed+1&&speed<v[nowt]){
            
            res+=(long double)(speed*2+1)/2.0;
            speed++;
        }else if(tmp>=speed){
            if(tmp2>=1&&speed<v[nowt]){
                res+=0.25;
            }
            res+=speed;
        }else{
            res+=(long double)(speed*2-1)/2.0;

            speed--;
        }
        if(t[nowt]==i){
            nowt++;
        }
    }
    cout<<res;
} 
