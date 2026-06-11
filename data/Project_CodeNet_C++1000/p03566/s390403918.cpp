#include <iostream>
#include <iomanip>
using namespace std;
typedef long double ld;
int main() {
    int n, t[100], s=0;
    ld w[50000], d=0.5, c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    for(int i=0;i<50000;i++){
        w[i]=100;
    }
    w[0]=0;
    for(int i=0;i<n;i++){
        ld v;
        cin>>v;
        for(int j=0;j<=t[i]*2;j++){
            w[s]=min(w[s], v);
            s++;
            if(j==t[i]*2)s--;
        }
    }
    for(int i=0;i<=s;i++){
        //cout<<i<<" "<<w[i]<<endl;
    }
    for(int i=1;i<=s;i++){
        w[i]=min(w[i-1]+d, w[i]);
    }
    w[s]=0;
    for(int i=s-1;i>=0;i--){
        w[i]=min(w[i], w[i+1]+d);
    }
    for(int i=1;i<=s;i++){
        ld a=w[i-1], b=w[i];
        c+=(a+b)/4;
        //cout<<i<<" "<<w[i]<<endl;
    }
    cout<<setprecision(20)<<c<<endl;
	return 0;
}