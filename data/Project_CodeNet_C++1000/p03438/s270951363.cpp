#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,A=0,B=0,asum=0,bsum=0;
    cin >> N;
    vector<long long int> a(N),b(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
        asum += a[i];
    }

    for(int i=0;i<N;i++){
        cin >> b[i];
        bsum += b[i];
    }

    for(int i=0;i<N;i++){
        if(a[i]<b[i]){
            if((b[i]-a[i])%2==1){
                A += (b[i]-a[i]+1)/2;
            }else{
                A += (b[i]-a[i])/2;
            }
        }else if(b[i]<a[i]){
            B += a[i]-b[i];
        }
    }

    if(A<=(bsum-asum) && B<=(bsum-asum)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}