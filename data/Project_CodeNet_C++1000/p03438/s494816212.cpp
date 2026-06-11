#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF  numeric_limits<int_fast64_t>::max();
#define intf int_fast64_t
int main(){
    intf n,cnt=0;
    cin >>n;
    vector<intf> a(n),b(n);
    for(auto &e:a) cin >>e;
    for(auto &f:b) cin >>f;
    // sort(a.begin(),a.end());
    // sort(b.begin(),b.end());

    rep(i,n){
        if(a[i]>b[i]){
            cnt -= (a[i]-b[i]);
           // cout << cnt <<"\t"<<a[i]<<"\t"<<b[i]<<endl;
        }else{
            cnt += ((b[i]-a[i])/2);
            //cout << cnt <<"\t"<<a[i]<<"\t"<<b[i]<<endl;
        }
    }

    if(cnt>=0){
        cout << "Yes" <<endl;
        //cout << cnt <<endl;
    }else{
        cout << "No"<<endl;
    }

}