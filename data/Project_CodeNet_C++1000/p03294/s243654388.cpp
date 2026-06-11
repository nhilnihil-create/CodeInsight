#include <iostream>
#include <numeric>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)

typedef long long ll;







int main(){



    
    int N;
    cin>>N;

    ll a[N];

    ll sum=0;

    rep(i,N){
        cin>>a[i];
        sum+=a[i]-1;
    }

    cout<<sum<<endl;


}
