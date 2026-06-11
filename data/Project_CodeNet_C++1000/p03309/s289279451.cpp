#include <bits/stdc++.h>
using namespace std;
#define N_MAX 1000000

int main(){
    //入力
int a[N_MAX];
int n;
long long sum=0;
long long ans=0;
int med=0;

    cin >> n;
    for(int i =0; i < n; ++i){
        cin >> a[i];
    }

    for(int i=0;i<n;++i){
        a[i]-=(i+1);
    }

    sort(a,a+n);
    if(n%2==0){
        med=round(double(a[n/2-1]+a[n/2])/2);
    }else{
        med=a[(n-1)/2];
    }

    for(int i=0;i<n;i++){
        ans+=abs(a[i]-med);
    }
    cout << ans <<endl;

    return 0;
}