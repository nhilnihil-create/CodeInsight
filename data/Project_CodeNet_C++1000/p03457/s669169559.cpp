#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
  	cin>>N;
    int a[N+10];
    int b[N+10];
    int c[N+10];
    a[0]=b[0]=c[0]=0;
    for (int i=1;i<=N;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    bool flag=true;
    for (int i=0;i<N;i++){
        if( abs(b[i]-b[i+1])+abs(c[i]-c[i+1])>abs(a[i]-a[i+1]) || (abs(b[i]-b[i+1])+abs(c[i]-c[i+1]))%2!=abs(a[i]-a[i+1])%2){
            flag=false;
            break;
        }
    }
    if (flag==true){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}