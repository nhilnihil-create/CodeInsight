#include<iostream>
using namespace std;

int main() {
    int N;
    cin>>N;
    long a[N], b[N], c[N];
    long sum = 0;
    for(int i=0;i<N;++i){
        cin>>a[i];
    }
    for(int i=0;i<N;++i){
        cin>>b[i];
        c[i] = a[i] - b[i];
        sum -= c[i];
    }

    bool ans = true;
    if(sum<0)ans=false;
    long plus = 0;
    long minus = 0;
    for(int i=0;i<N;++i){
        if(c[i]>=0){
            plus+=c[i];
        }
        else{
            if(-c[i]%2==1){
                minus += -c[i]/2+1;
            }
            else{
                minus += -c[i]/2;
            }
        }
    }
    if(sum < plus | sum < minus)ans=false;
    /**
    int plusnum = 0;
    int minusnum = 0;
    for(int i=0;i<N;++i){
        if(a[i] >= b[i]){
            plus += a[i] - b[i];
            if(a[i]>b[i]){
                plusnum++;
            }
        }
        else {
            minus += b[i] - a[i];
            minusnum++;
        }
    }
    if(plus>sum)ans=false;
    if(minus%2==0){
        if(minus/2>sum)ans=false;
    }
    else{
        if(minus/2+1>sum)ans=false;
    }
    if(plusnum>sum)ans=false;
    if(minusnum>sum)ans=false;
    **/
    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
