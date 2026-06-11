#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int a[300000];
    int max=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max){
            max=a[i];
        }
    }
    int max1=0;
    for(int i=0;i<n;i++){
        if(abs(2*a[i]-max)<abs(2*max1-max)){
            max1=a[i];
        }
    }
    cout<<max<<" "<<max1;
    return 0;
}