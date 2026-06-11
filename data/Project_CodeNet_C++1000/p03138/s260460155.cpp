#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>


using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<int> cnt(41,0);
    ll bi=1,ans=0,now=0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        bitset<41> b(A[i]);
        for(int i=0; i<41; i++){
            cnt[i]+=b[i];
        }
    }
    for(int i=0; i<40; i++) bi*=2;

    reverse(cnt.begin(),cnt.end());
    for(int i=0; i<41; i++){
        if(cnt[i]*2>=N){ // 0にする
            ans+=bi*cnt[i];
        }else{
            if(bi+now>K){
                ans+=bi*cnt[i];
            }else{
                ans+=(N-cnt[i])*bi;
                now+=bi;
            }
        }
        bi/=2;
    }

    cout << ans << endl;



    return 0;
}