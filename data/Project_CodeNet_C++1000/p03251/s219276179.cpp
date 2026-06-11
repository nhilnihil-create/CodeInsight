#include <bits/stdc++.h>
using namespace std;
    int main(){
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        int a[n],b[m];
        for(int i=0;i<n;i++)cin >> a[i];
        for(int j=0;j<m;j++)cin >> b[j];
        sort(a,a+n);
        sort(b,b+m);
        int flag=0;
        if(b[0]>a[n-1]){
            for(int i=a[n-1]+1;i<=b[0];i++){
                if(i>x && i<=y)flag++;
            }
            if(flag>0)cout << "No War" << endl;
            else cout << "War" << endl;
        }
        else cout << "War" << endl;
    }