#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N; cin >> N;
    int a[200200], b[200200];
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    for(int i=0; i<N; i++){
        cin >> b[i];
    }
    ll ans=0;
    for(int i=0; i<31; i++){
    //まず,i桁目で0+1となるのと1+0となるのを数える
        int num_a_0=0, num_a_1=0, num_b_0=0, num_b_1=0;
        for(int j=0; j<N; j++){
            if(a[j]%( 1<<(i+1) ) >= (1<<i) ) num_a_1++;
            else num_a_0++;
            if(b[j]%( 1<<(i+1) ) >= (1<<i) ) num_b_1++;
            else num_b_0++;
        }
        if(i==0){
            ans += ( (ll) num_a_0*num_b_1+ (ll) num_a_1*num_b_0)%2LL;
            continue;
        }
    //一個下の桁からの繰り上がりを考える
        int a1[200200], b1[200200]; //aとかの下i-1桁を入れる
        for(int j=0; j<N; j++){
            a1[j] = a[j] % (1<< (i) );
            b1[j] = b[j] % (1<< (i) );
        }
        sort(a1,a1+N);
        sort(b1,b1+N);
        ll num_kuri=0;
        int r=N-1;
        for(int j=0; j<N; j++){
            while(r>=0 && a1[j]+b1[r] >=(1<<i) ){
                r--;
            }
            num_kuri +=N-1-r;
        }
        ans +=( (ll) num_a_0*num_b_1+ (ll) num_a_1*num_b_0 + num_kuri) %2LL *(1<<i);
    }
    cout << ans << endl;
}