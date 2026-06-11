#include <bits/stdc++.h>

using namespace std;

char d[]={'L','U','D','R'};

int main(){
    int h,w,n;
    cin >> h >> w >> n;
    int x,y;
    cin >> y >> x;
    int v[]={x,y,y,x};
    int ch[]={-1,-1,1,1};
    int lim[]={w,h,h,w};
    string a,b;
    cin >> a >> b;
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            //cout << v[i] << endl;
            if(a[j]==d[i]){
                v[i]+=ch[i];
            }
            if(v[i]>lim[i] || v[i]<1){
                cout << "NO" << endl;
                return 0;
            }
            if(b[j]==d[3-i]){
                v[i]+=ch[3-i];
            }
            if(v[i]>lim[i]){
                v[i]--;
            }
            if(v[i]<1){
                v[i]++;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
